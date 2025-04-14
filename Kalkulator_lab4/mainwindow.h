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
    void on_Button_plus_clicked();

    void on_Button_equal_clicked();

private:
    Ui::MainWindow *ui;
    QString currentInput;
    QString uzywanyoperator;
    double storedValue=0;
    obliczenia oblicz;
};

#endif // MAINWINDOW_H
