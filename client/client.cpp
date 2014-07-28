#include "client.h"

Client::Client(QObject *parent) :
    QObject(parent)
{
    QObject::connect(&m_tcpSocket, SIGNAL(disconnected()),
                     this, SLOT(socketDisconnected()));

    QObject::connect(&m_tcpSocket, SIGNAL(readyRead()),
                     this, SLOT(read()));

    m_tcpSocket.abort();
    m_tcpSocket.connectToHost("localhost", 55555);
    m_tcpSocket.write("MESSAGE Hi!\n");
}

Client::~Client()
{
    m_tcpSocket.abort();
}

void Client::socketDisconnected()
{
    QCoreApplication::instance()->quit();
}

void Client::read()
{
    const QByteArray *command_ptr = new QByteArray(m_tcpSocket.readLine(100));
    qDebug() << "Read from Server: " << *command_ptr;
}
