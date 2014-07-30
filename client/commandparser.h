#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <QString>

class ClientDelegate;

class CommandParser
{
public:
    CommandParser(ClientDelegate* delegate);
    void parse(QString command);

private:
    ClientDelegate* m_delegate;
};

#endif // COMMANDPARSER_H
