#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion")); //spojnosc miedzy roznymi PC
    MainWindow w;
    w.show();
    return a.exec();
}
