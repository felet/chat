#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork>

class Client : public QObject
{
    Q_OBJECT

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

private:
    QTcpSocket* m_tcpSocket;
    QString m_name;
};

#endif // CLIENT_H
