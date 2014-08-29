#ifdef TEST

#include <QtTest>
#include "tests/commandparsertest.h"

QTEST_MAIN(CommandParserTest);

#else

#include <QApplication>
#include "client.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Client client(&w);
    return a.exec();
}

#endif
