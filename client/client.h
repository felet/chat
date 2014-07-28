#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork>

class Client : public QObject
{
    Q_OBJECT

private:
    QTcpSocket m_tcpSocket;

public:
    explicit Client(QObject *parent = 0);
    ~Client();

public slots:
    void socketDisconnected();
    void read();
};

#endif // CLIENT_H
