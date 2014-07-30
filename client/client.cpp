#include <QTextEdit>
#include <QPushButton>

#include "client.h"
#include "mainwindow.h"


Client::Client(MainWindow* window, QObject *parent) :
    QObject(parent), m_window(window)
{
    QObject::connect(&m_tcpSocket, SIGNAL(disconnected()),
                     this, SLOT(socketDisconnected()));
    QObject::connect(&m_tcpSocket, SIGNAL(readyRead()),
                     this, SLOT(read()));

    m_tcpSocket.abort();
    m_tcpSocket.connectToHost("localhost", 55555);
    m_tcpSocket.write("MESSAGE Hi!\n");

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
}

void Client::socketDisconnected()
{
    QCoreApplication::instance()->quit();
}

void Client::read()
{
    const QByteArray command_ptr(m_tcpSocket.readLine(100));
    qDebug() << "Read from Server: " << command_ptr;
    QString str = "Server: ";
    str += command_ptr;

    // TODO: Don't replace the entire conversation, append properly instead.
    m_conversation->setText(str);
}

void Client::sendMessage()
{
    QString message = m_input->toPlainText();
    m_input->clear();
    QString command("MESSAGE ");
    command += message;
    m_tcpSocket.write(command.toLocal8Bit());
}
