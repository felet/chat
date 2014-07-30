#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTextEdit>
#include <QPushButton>
#include <QtNetwork>

class MainWindow;
class FailedToInitializeUI {};

class Client : public QObject
{
    Q_OBJECT

public:
    Client(MainWindow* window, QObject *parent = 0);
    ~Client();

public slots:
    void socketDisconnected();
    void read();
    void sendMessage();

private:
    QTcpSocket m_tcpSocket;
    MainWindow* m_window;
    QTextEdit* m_conversation;
    QTextEdit* m_input;
    QPushButton* m_send;
};

#endif // CLIENT_H
