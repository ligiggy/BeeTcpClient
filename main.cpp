#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<QByteArray>("QByteArray");
    qRegisterMetaType<QByteArray>("QByteArray&");

    MainWindow w;
    w.show();

    return a.exec();
}
