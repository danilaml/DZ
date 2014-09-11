#include <QLayout>
#include <QMessageBox>

#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Server),
    tcpServer(0),
    clientSocket(0),
    networkSession(0),
    blockSize(0)
{
    ui->setupUi(this);
    statusLabel = new QLabel;
    quitButton = new QPushButton(tr("Quit"), this);
    quitButton->setAutoDefault(false);
    sendButton = new QPushButton(tr("Send"), this);
    sendButton->setEnabled(false);
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    chatLineEdit = new QLineEdit(this);

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("Trololo"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) != QNetworkConfiguration::Discovered)
        {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    }
    else
    {
        sessionOpened();
    }

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(sendButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addWidget(textEdit);
    mainLayout->addWidget(chatLineEdit);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("TxtServer"));
}

Server::~Server()
{
    delete ui;
}

void Server::sessionOpened()
 {
     // Save the used configuration
     if (networkSession)
     {
         QNetworkConfiguration config = networkSession->configuration();
         QString id;
         if (config.type() == QNetworkConfiguration::UserChoice)
             id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
         else
             id = config.identifier();

         QSettings settings(QSettings::UserScope, QLatin1String("Trololo"));
         settings.beginGroup(QLatin1String("QtNetwork"));
         settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
         settings.endGroup();
     }

     tcpServer = new QTcpServer(this);
     if (!tcpServer->listen(QHostAddress::LocalHost, tcpServer->serverPort()))
     {
         QMessageBox::critical(this, tr("TxtServer"),
                               tr("Unable to start the server: %1.")
                               .arg(tcpServer->errorString()));
         close();
         return;
     }

     // use IPv4 localhost (because other don't work on my pc and because code in fortuneServer was strange there)
     statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                             "Run the TxtSender example now.")
                          .arg(tcpServer->serverAddress().toString()).arg(tcpServer->serverPort()));
 }

void Server::acceptConnection()
{
    clientSocket = tcpServer->nextPendingConnection();
    sendButton->setEnabled(true);
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(startRead()));
    connect(clientSocket, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
}

void Server::startRead()
{
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_5_2);

    if (blockSize == 0)
    {
        if (clientSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }

    if (clientSocket->bytesAvailable() < blockSize)
             return;

    blockSize = 0;
    QString newMessage;
    in >> newMessage;
    textEdit->textCursor().insertText("<client>: " + newMessage + '\n');
}

void Server::sendMessage()
{
    if(clientSocket)
    {
        sendButton->setEnabled(false);

        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        QString tmp = chatLineEdit->text();
        chatLineEdit->clear();
        out << (quint16)tmp.length();
        out << tmp;
        clientSocket->write(block);

        textEdit->textCursor().insertText("<you>: " + tmp + '\n');

        sendButton->setEnabled(true);
    }
}

void Server::clientDisconnected()
{
    sendButton->setEnabled(false);
    QMessageBox::warning(this, tr("Warning!"), tr("Client disconnected"));
}
