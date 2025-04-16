#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QWidget>
#include <QFile>
#include "obliczenia.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Wyswietlacz->setDigitCount(10);
    ui->Wyswietlacz->setMode(QLCDNumber::Dec);
    ui->Wyswietlacz->setSegmentStyle(QLCDNumber::Flat);
    ui->miniwyswietlacz->setDigitCount(10);
    ui->miniwyswietlacz->setMode(QLCDNumber::Dec);
    ui->miniwyswietlacz->setSegmentStyle(QLCDNumber::Flat);
    connect(ui->O_autorze, &QAction::triggered, this, &MainWindow::OAutorze);
    connect(ui->Button_0, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->Button_1, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->Button_2, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->Button_3, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->Button_4, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->Button_5, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->Button_6, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->Button_7, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->Button_8, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->Button_9, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(ui->Button_DOT, &QPushButton::clicked, this, &MainWindow::dotClicked);
    connect(ui->Button_CLEAR, &QPushButton::clicked, this, &MainWindow::clearClicked);
    connect(ui->Button_BACKSPACE, &QPushButton::clicked, this, &MainWindow::backspaceClicked);
    connect(ui->Button_plus, &QPushButton::clicked, this, &MainWindow::operatorclicked);
    connect(ui->Button_minus, &QPushButton::clicked, this, &MainWindow::operatorclicked);
    connect(ui->Button_mult, &QPushButton::clicked, this, &MainWindow::operatorclicked);
    connect(ui->Button_div, &QPushButton::clicked, this, &MainWindow::operatorclicked);
    connect(ui->Button_modulo, &QPushButton::clicked, this, &MainWindow::operatorclicked);
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::OAutorze(){
    QMessageBox::information(this, "O autorze",
                             "Zrobione przez: Filip Lenart 287116\n\n"
                             "Kalkulator prosty, projekt cząstkowy QT.\n"
                            );
}
void MainWindow::digitClicked(){                                   //obsługa przyciskow cyfr 0-9
    if (currentInput.length() >= 10) return;                      //limit INPUTU Z KLAWISZY do 10 cyfr na wyswietlaczu
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;
    if(currentInput=='0'){
        currentInput.clear();
    }
    currentInput += button->text();                               //zamiana napisu z przyciskow cyfr na string
    ui->Wyswietlacz->display(currentInput);
    if(obliczenia.getstoredValue()){
        ui->miniwyswietlacz->display(obliczenia.getstoredValue());
    }
}

void MainWindow::dotClicked(){                                  //obsługa kropki
    if(currentInput.isEmpty()){
        currentInput += "0.";
        ui->Wyswietlacz->display(currentInput);
        if(obliczenia.getstoredValue()){
            ui->miniwyswietlacz->display(obliczenia.getstoredValue());
        }
    }
    if (currentInput.length() >= 10) return;
    if(!currentInput.contains('.')) {
         currentInput += ".";
         ui->Wyswietlacz->display(currentInput);
      }

}

void MainWindow::clearClicked(){                                  //obsługa CLEAR
    obliczenia.setstoredValue(0);
    currentInput.clear();
    uzywanyoperator.clear();
    ui->miniwyswietlacz->display(obliczenia.getstoredValue());
    ui->Wyswietlacz->display(0);
    ui->Operator_label->setText(uzywanyoperator);
    obliczenia.error_type=0;
}

void MainWindow::backspaceClicked(){                                  //obsługa backspace
    if(!currentInput.isEmpty()){
        currentInput.chop(1);
    }
    ui->Wyswietlacz->display(currentInput.isEmpty() ? "0" : currentInput);
}
void MainWindow::on_Button_ZNAK_clicked()                           //obsługa zmiany znaku
{
    if(currentInput.isEmpty()){
        return;
    }
    if (currentInput.startsWith("-")) {
        currentInput.remove(0, 1);
    } else if (!currentInput.isEmpty() && currentInput != "0") {
        currentInput.prepend("-");
    }

    ui->Wyswietlacz->display(currentInput);
}

void MainWindow::operatorclicked(){                                                             //obsluga przyciskow operatorów
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    ui->Wyswietlacz->display(0);

    if(!obliczenia.getstoredValue()){                                                                           //jesli storedvalue jest puste(zero)
        obliczenia.setstoredValue(currentInput.toDouble());
        currentInput.clear();
    }
    else {                                                                                      //jesli storedvalue coś zawiera
        MainWindow::on_Button_equal_clicked();
    }
    uzywanyoperator = button->text();                                                           //zamiana napisu z przycisków operatorów na string
    ui->Operator_label->setText(uzywanyoperator);
    ui->miniwyswietlacz->display(obliczenia.getstoredValue());
}


void MainWindow::on_Button_equal_clicked()                                                       //obsługa znaku równości
{
    ui->miniwyswietlacz->display(0);
    if(uzywanyoperator=='x' && currentInput.isEmpty()){                                          //nie pomnozenie przez zero po pierwszym dzialaniu - dla mnożenia
        currentInput='1';
    }
    obliczenia.setstoredValue(obliczenia.oblicz(uzywanyoperator, obliczenia.getstoredValue(), currentInput.toDouble()));
    if(obliczenia.error_type==1){
        MainWindow::clearClicked();
        QMessageBox::critical(this, "Błąd", "Dzielenie przez zero");
    };
    ui->Wyswietlacz->display(obliczenia.getstoredValue());
    currentInput.clear();
}



void MainWindow::on_konwersja10_8_triggered()
{
    if(!currentInput.isEmpty()){
        ui->Wyswietlacz->display(obliczenia.decimalToOctal(currentInput.toInt()));
        currentInput.clear();
        return;
    }
        ui->Wyswietlacz->display(obliczenia.decimalToOctal(obliczenia.getstoredValue()));
        obliczenia.setstoredValue(0);

}




void MainWindow::on_actionREADME_triggered()
{
    QFile file("README.md");                                                    //plik .md wstaw obok .exe!!!

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {                    //jeśli nie otworzy README
        QMessageBox::warning(this, "Błąd", "Nie można otworzyć README.md");
        return;
    }

    QTextStream in(&file);                                                          //zamiana w messagebox
    QString content = in.readAll();
    QMessageBox::information(this, "README", content);

}

