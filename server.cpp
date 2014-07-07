#include "server.h"

Server::Server(QObject *parent)
    : QObject(parent)
{
    m_tcpServer = new QTcpServer();
    QObject::connect(m_tcpServer, SIGNAL(newConnection()),
                     this, SLOT(newConnection()));
    if (m_tcpServer->listen(QHostAddress::Any, m_port))
    {
        qDebug() << "Server assigned to port: " << m_port;
    }
    else
    {
        qDebug() << "Assigning port:" << m_port << " failed!";
    }
}

Server::~Server()
{
    delete m_tcpServer;
    while(!m_clients.empty())
    {
        delete m_clients.front();
        m_clients.pop_front();
    }
}

void Server::newConnection()
{
    qDebug() << "New connection!!";

    Client* client = new Client(m_tcpServer->nextPendingConnection());

    m_clients.push_back(client);
    QObject::connect(client, SIGNAL(disconnected(Client*)),
                     this, SLOT(clientDisconnected(Client*)));

    client->write("Welcome!\n");
}

void Server::clientDisconnected(Client* client)
{
    m_clients.removeOne(client);
    delete client;
    qDebug() << "Client disconnected!";
}
