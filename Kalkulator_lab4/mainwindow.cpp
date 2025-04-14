#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
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
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::OAutorze(){
    QMessageBox::information(this, "About the Author",
                             "Zrobione przez: Filip Lenart 287116\n\n"
                             "Prosty kalkulator, projekt cząstkowy QT.\n"
                            );
}
void MainWindow::digitClicked(){
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;
    currentInput += button->text();
    ui->Wyswietlacz->display(currentInput);

}
void MainWindow::dotClicked(){
    if(currentInput.isEmpty()){
        currentInput += "0.";
        ui->Wyswietlacz->display(currentInput);
    }
    if(!currentInput.contains('.')) {
         currentInput += ".";
         ui->Wyswietlacz->display(currentInput);
      }
}
void MainWindow::clearClicked(){
    storedValue=0;
    ui->miniwyswietlacz->display(storedValue);
    currentInput.clear();
    ui->Wyswietlacz->display(0);
}
void MainWindow::backspaceClicked(){
    if(!currentInput.isEmpty()){
        currentInput.chop(1);
    }
    ui->Wyswietlacz->display(currentInput.isEmpty() ? "0" : currentInput);
}

void MainWindow::on_Button_plus_clicked()
{
    uzywanyoperator='+';
    if(!currentInput.isEmpty()){
        storedValue = oblicz.suma(storedValue, currentInput.toDouble());
        currentInput.clear();
        ui->Wyswietlacz->display(0);
    }
    ui->miniwyswietlacz->display(storedValue);
}





void MainWindow::on_Button_equal_clicked()
{
    double wynik=0;
    if (uzywanyoperator=='+'){
        wynik=oblicz.suma(storedValue,currentInput.toDouble());
    }
    ui->Wyswietlacz->display(wynik);
    ui->miniwyswietlacz->display(0);

}

