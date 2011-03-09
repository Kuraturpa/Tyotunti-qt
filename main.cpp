#include <QtGui/QApplication>
#include "mainwindow.h"
#include "userwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    UserWindow w;
    w.show();


    return a.exec();
}
