#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QLabel>
#include <QtNetwork/QtNetwork>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class Server;
}

class Server : public QDialog
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

private slots:
    void sessionOpened();
    void acceptConnection();
    void sendMessage();
    void startRead();
    void clientDisconnected();

private:
    Ui::Server *ui;
    QLabel *statusLabel;
    QPushButton *quitButton;
    QPushButton *sendButton;
    QLineEdit *chatLineEdit;
    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;
    QNetworkSession *networkSession;
    QTextEdit *textEdit;
    quint16 blockSize;
};

#endif // SERVER_H
