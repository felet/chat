#include "client.h"

Client::Client(QTcpSocket *tcpSocket, QObject *parent) :
    QObject(parent),
    m_tcpSocket(tcpSocket)
{
    QObject::connect(tcpSocket, SIGNAL(disconnected()),
                     this, SLOT(socketDisconnected()));

    QObject::connect(tcpSocket, SIGNAL(readyRead()),
                     this, SLOT(read()));
}

void Client::socketDisconnected()
{
    emit disconnected(this);
}

Client::~Client()
{
    m_tcpSocket->deleteLater();
}

void Client::read()
{
    const QByteArray *command_ptr = new QByteArray(m_tcpSocket->readLine(100));
    qDebug() << "Read from client: " << *command_ptr;

    if (command_ptr->startsWith("MESSAGE "))
    {
        emit forwardMessage(this, command_ptr);
    }
    else if (command_ptr->startsWith("SET_NAME "))
    {
        qDebug() << "Setting name for client";
        m_name = command_ptr->right(command_ptr->length() - strlen("SET_NAME "));
    }
    else
    {
        delete command_ptr;
        const QByteArray note("Unknown command!\n");
        qDebug() << note;
        write(note);
    }
}

void Client::write(const QByteArray& data)
{
    m_tcpSocket->write(data);
}
