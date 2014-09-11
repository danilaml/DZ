#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QtNetwork/QtNetwork>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class Client;
}

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

private slots:
    void sessionOpened();
    void displayError(QAbstractSocket::SocketError socketError);
    void sendMessage();
    void startRead();
    void enableSendButton();
    void serverDisconnected();
    void enableAddressChange();
    void disableAddressChange();
    void tryConnect();

private:
    Ui::Client *ui;
    QLabel *hostLabel;
    QLabel *portLabel;
    QComboBox *hostCombo;
    QLineEdit *portLineEdit;
    QLineEdit *chatLineEdit;
    QLabel *statusLabel;
    QPushButton *quitButton;
    QPushButton *sendButton;
    QPushButton *connectButton;
    QTcpSocket *serverSocket;
    QNetworkSession *networkSession;
    QTextEdit *textEdit;
    quint16 blockSize;
};

#endif // CLIENT_H
