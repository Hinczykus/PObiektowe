#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    QString currentInput;
};

#endif // MAINWINDOW_H
