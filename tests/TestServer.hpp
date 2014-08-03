#include "server.h"

#include <QtTest>

class TestServer: public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();

    void init();
    void cleanup();

    void testDummy();
};
