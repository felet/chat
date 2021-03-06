#include <QTextEdit>
#include <QPushButton>

#include "client.h"
#include "mainwindow.h"
#include "commandparser.h"

namespace {

bool isCommand(QString str)
{
    return str[0] == '/';
}

QString createMessage(QString message)
{
    return "MESSAGE " + message;
}

}

Client::Client(MainWindow* window, QObject *parent) :
    QObject(parent), m_window(window), m_parser(new CommandParser(this)), m_name("default")
{
    QObject::connect(&m_tcpSocket, SIGNAL(disconnected()),
                     this, SLOT(socketDisconnected()));
    QObject::connect(&m_tcpSocket, SIGNAL(readyRead()),
                     this, SLOT(read()));

    m_tcpSocket.abort();
    m_tcpSocket.connectToHost("localhost", 55555);
    m_tcpSocket.write(createMessage("hi").toLocal8Bit());

    m_conversation = window->centralWidget()->findChild<QTextEdit*>("textEdit_1");
    m_input = window->centralWidget()->findChild<QTextEdit*>("textEdit_2");
    m_send = window->centralWidget()->findChild<QPushButton*>("pushButton");

    if (!m_conversation || !m_input || !m_send) {
        throw new FailedToInitializeUI;
    }

    QObject::connect(m_send, SIGNAL(clicked()), this, SLOT(sendMessage()));
}

Client::~Client()
{
    m_tcpSocket.abort();
    delete m_parser;
}

void Client::setName(QString name)
{
    QString command = "SET_NAME ";
    command += name;
    m_tcpSocket.write(command.toLocal8Bit());
    m_name = name;
}

void Client::socketDisconnected()
{
    QCoreApplication::instance()->quit();
}

void Client::read()
{
    const QByteArray command_ptr(m_tcpSocket.readLine(100));
    m_conversation->append(command_ptr);
}

void Client::sendMessage()
{
    QString message = m_input->toPlainText();
    m_input->clear();

    if (isCommand(message)) {
        m_parser->parse(message);
    } else {
        QString local;
        local.append(m_name);
        local.append(": ");
        local.append(message);
        m_conversation->append(local);
        m_tcpSocket.write(createMessage(message).toLocal8Bit());
    }
}
