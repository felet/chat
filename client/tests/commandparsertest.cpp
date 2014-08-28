#include <QtTest>
#include "commandparsertest.h"
#include "commandparser.h"

CommandParserTest::CommandParserTest(QObject *parent) :
    QObject(parent)
{
}

void CommandParserTest::initTestCase()
{
}

void CommandParserTest::cleanupTestCase()
{
}

void CommandParserTest::init()
{
}

void CommandParserTest::cleanup()
{
}

void CommandParserTest::testEmptyName()
{
    FakeClientDelegate delegate;
    CommandParser parser(&delegate);
    parser.parse("/name");
    QCOMPARE(QString(""), delegate.m_name);
}

void CommandParserTest::testRegularName()
{
    FakeClientDelegate delegate;
    CommandParser parser(&delegate);
    parser.parse("/name my_sweet_userid");
    QCOMPARE(QString("my_sweet_userid"), delegate.m_name);
}
