#include <QLayout>
#include <QMessageBox>

#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client),
    networkSession(0),
    blockSize(0)
{
    ui->setupUi(this);
    hostLabel = new QLabel(tr("&Server name:"));
    portLabel = new QLabel(tr("S&erver port:"));

    hostCombo = new QComboBox;
    hostCombo->setEditable(true);

    statusLabel = new QLabel;
    quitButton = new QPushButton(tr("Quit"), this);
    quitButton->setAutoDefault(false);
    sendButton = new QPushButton(tr("Send"), this);
    sendButton->setEnabled(false);
    connectButton = new QPushButton(tr("Connect"), this);
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);

    // find out name of this machine
    QString name = QHostInfo::localHostName();
    if (!name.isEmpty())
    {
        hostCombo->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            hostCombo->addItem(name + QChar('.') + domain);
    }
    if (name != QString("localhost"))
        hostCombo->addItem(QString("localhost"));
    // find out IP addresses of this machine
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // add non-localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (!ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }
    // add localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }

    portLineEdit = new QLineEdit(this);
    portLineEdit->setValidator(new QIntValidator(1, 65535, this));

    chatLineEdit = new QLineEdit(this);

    hostLabel->setBuddy(hostCombo);
    portLabel->setBuddy(portLineEdit);

    statusLabel = new QLabel(tr("This app requires that you run the "
                                "TxtServer example as well."));

    serverSocket = new QTcpSocket(this);

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(connectButton, SIGNAL(clicked()), this, SLOT(tryConnect()));
    connect(serverSocket, SIGNAL(readyRead()), this, SLOT(startRead()));
    connect(serverSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(serverSocket, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));
    connect(serverSocket, SIGNAL(connected()), this, SLOT(disableAddressChange()));
    connect(serverSocket, SIGNAL(disconnected()), this, SLOT(enableAddressChange()));

    QGridLayout *someLayout = new QGridLayout;
    someLayout->addWidget(hostLabel, 0, 0);
    someLayout->addWidget(hostCombo, 0, 1);
    someLayout->addWidget(portLabel, 1, 0);
    someLayout->addWidget(portLineEdit, 1, 1);
    someLayout->addWidget(statusLabel, 2, 0, 1, 2);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(connectButton);
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(sendButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(someLayout);
    mainLayout->addWidget(textEdit);
    mainLayout->addWidget(chatLineEdit);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("TxtClient"));
    portLineEdit->setFocus();

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
                QNetworkConfiguration::Discovered)
        {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    }
}

Client::~Client()
{
    delete ui;
}

void Client::startRead()
{
    QDataStream in(serverSocket);
    in.setVersion(QDataStream::Qt_5_2);

    if (blockSize == 0)
    {
        if (serverSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }

    if (serverSocket->bytesAvailable() < blockSize)
             return;

    blockSize = 0;
    QString newMessage;
    in >> newMessage;
    textEdit->textCursor().insertText("<server>: " + newMessage + '\n');
}

void Client::sendMessage()
{
    sendButton->setEnabled(false);

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    QString tmp = chatLineEdit->text();
    chatLineEdit->clear();
    out << (quint16)tmp.length();
    out << tmp;
    serverSocket->write(block);

    textEdit->textCursor().insertText("<you>: " + tmp + '\n');

    sendButton->setEnabled(true);
}

void Client::sessionOpened()
{
    // Save the used configuration
    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice)
        id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    else
        id = config.identifier();

    QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
    settings.beginGroup(QLatin1String("QtNetwork"));
    settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
    settings.endGroup();

    statusLabel->setText(tr("This examples requires that you run the "
                            "TxtServer example as well."));
    enableSendButton();
}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    serverSocket->close();
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("TxtClient"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("TxtClient"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("TxtClient"),
                                 tr("The following error occurred: %1.")
                                 .arg(serverSocket->errorString()));
    }
    enableAddressChange();
}

void Client::enableSendButton()
{
    sendButton->setEnabled((!networkSession || networkSession->isOpen()) &&
                                 !hostCombo->currentText().isEmpty() &&
                                 !portLineEdit->text().isEmpty());
}

void Client::serverDisconnected()
{
    sendButton->setEnabled(false);
    enableAddressChange();
    QMessageBox::warning(this, tr("Warning!"), tr("Disconnected"));
}

void Client::enableAddressChange()
{
    hostCombo->setEnabled(true);
    portLineEdit->setEnabled(true);
}

void Client::disableAddressChange()
{
    hostCombo->setEnabled(false);
    portLineEdit->setEnabled(false);
}

void Client::tryConnect()
{
    if (connectButton->text()[0] == 'D')
    {
        connectButton->setText("Connect");
        serverSocket->close();
        return;
    }
    disableAddressChange();
    serverSocket->connectToHost(hostCombo->currentText(), portLineEdit->text().toInt());

    if (serverSocket->waitForConnected(3000))
    {
        enableSendButton();
        connectButton->setText("Disconnect");
    }
    else
    {
        QMessageBox::information(this, tr("TxtClient"), tr("Connection timed out"));
        enableAddressChange();
    }
}
