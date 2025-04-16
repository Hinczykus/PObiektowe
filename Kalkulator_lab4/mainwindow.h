#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "obliczenia.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void digitClicked();
    void dotClicked();
    void backspaceClicked();
    void clearClicked();
    void OAutorze();
    void operatorclicked();
    void on_Button_equal_clicked();
    void on_Button_ZNAK_clicked();

    void on_konwersja10_8_triggered();

    void on_actionREADME_triggered();

private:
    Ui::MainWindow *ui;
    QString currentInput;
    QString uzywanyoperator;
    obliczenia obliczenia;
};

#endif // MAINWINDOW_H
