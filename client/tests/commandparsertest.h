#ifndef COMMANDPARSERTEST_H
#define COMMANDPARSERTEST_H

#include <QObject>
#include "clientdelegate.h"

class FakeClientDelegate : public ClientDelegate
{
public:
    virtual void setName(QString name) { m_name = name; }
    QString m_name;
};

class CommandParserTest : public QObject
{
    Q_OBJECT
public:
    explicit CommandParserTest(QObject *parent = 0);

private slots:
    void testEmptyName();
    void testRegularName();
};

#endif // COMMANDPARSERTEST_H
