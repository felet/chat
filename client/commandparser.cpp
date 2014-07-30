#include "commandparser.h"
#include "clientdelegate.h"

CommandParser::CommandParser(ClientDelegate* delegate)
    : m_delegate(delegate)
{
}

void CommandParser::parse(QString command)
{
    m_delegate->setName(command.right(command.length()-1));
}
