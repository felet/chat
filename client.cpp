#include "client.h"

Client::Client(QTcpSocket* tcpSocket, QObject *parent) :
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
    QByteArray line = m_tcpSocket->readLine(100);
    qDebug() << line;
}

void Client::write(const QByteArray& data)
{
    m_tcpSocket->write(data);
}
