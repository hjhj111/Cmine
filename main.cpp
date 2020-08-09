#include "mainwindow.h"
#include "cmine.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //Cmine cmine;
    //cmine.show();
    return a.exec();
}
