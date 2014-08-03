#include "TestClient.hpp"
#include "TestServer.hpp"

#include <QtTest>

//QTEST_MAIN(TestClient)
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    TestClient testClient;
    TestServer testServer;

    return QTest::qExec(&testClient, argc, argv) |
           QTest::qExec(&testServer, argc, argv);
}
