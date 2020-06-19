#include "mainwindow.h"
#include <windows.h>


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_DisableHighDpiScaling);
    qputenv("QT_DEVICE_PIXEL_RATIO", QByteArray("1"));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
