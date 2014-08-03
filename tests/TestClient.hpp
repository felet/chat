#include "client.h"

#include <QtTest>

class TestClient: public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();

    void init();
    void cleanup();

    void testIsCommand();
};
