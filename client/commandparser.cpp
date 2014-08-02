#include "commandparser.h"
#include "clientdelegate.h"

CommandParser::CommandParser(ClientDelegate* delegate)
    : m_delegate(delegate)
{
}

void CommandParser::parse(QString command)
{
    // TODO: Retrieve the name after the space
    int delim = command.indexOf(' ');
    if (delim < 0)
        return;
    m_delegate->setName(command.right(command.length()-delim-1));
}
