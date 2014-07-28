#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork>

#include "client.h"

class Server : public QObject
{
    Q_OBJECT

private:
    QTcpServer *m_tcpServer;
    QList<Client*> m_clients;
    static const quint16 m_port = 55555;

public:
    ~Server();
    explicit Server(QObject *parent = 0);

signals:

public slots:
    void newConnection();
    void clientDisconnected(Client*);
    void forwardMessage(const Client *, const QByteArray*);
};

#endif // SERVER_H
