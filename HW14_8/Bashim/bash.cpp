#include <QLayout>

#include "bash.h"
#include "ui_bash.h"

Bash::Bash(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bash)
{
    ui->setupUi(this);

    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    loadButton = new QPushButton(tr("Load"), this);
    quitButton = new QPushButton(tr("Quit"), this);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(loadButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(textEdit);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply *)),
            this, SLOT(replyFinished(QNetworkReply *)));
    connect(loadButton, SIGNAL(clicked()), this, SLOT(requestQuotes()));

}

Bash::~Bash()
{
    delete ui;
}

void Bash::requestQuotes()
{
    manager->get(QNetworkRequest(QUrl("http://bash.im/rss")));
    //delete later;
    xmlReader.addData(networkReply->readAll()); // readyRead()?
}

void Bash::replyFinished(QNetworkReply *reply)
{
    networkReply = reply; // caution, if reply already init'ed
    connect(networkReply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    //connect(reply, SIGNAL(finished()), reply, SLOT(deleteLater()));
}
