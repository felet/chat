#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork>

class Client : public QObject
{
    Q_OBJECT

private:
    QTcpSocket* m_tcpSocket;

public:
    Client(QTcpSocket *tcpSocket, QObject *parent = 0);
    ~Client();
    void write(const QByteArray& data);

signals:
    void disconnected(Client*);
    void forwardMessage(const Client*, const QByteArray*);

public slots:
    void socketDisconnected();
    void read();
};

#endif // CLIENT_H
