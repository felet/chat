#include <QApplication>
#include <mainwindow.h>

#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Client client(&w);
    return a.exec();
}
