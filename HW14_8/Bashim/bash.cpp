#include <QLayout>
#include <QTextCodec>

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
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

}

Bash::~Bash()
{
    delete ui;
}

void Bash::requestQuotes()
{
    loadButton->setEnabled(false);
    loadButton->setText(tr("Next 10"));
    textEdit->clear();
    if (networkReply)
    {
        networkReply->disconnect(this);
        networkReply->deleteLater();
    }
    networkReply = manager->get(QNetworkRequest(QUrl("http://bash.im/rss/")));
    connect(networkReply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
}

void Bash::replyFinished(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    loadButton->setEnabled(true);
}

void Bash::slotReadyRead()
{
    int statusCode = networkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if (statusCode >= 200 && statusCode < 300)
    {
        QByteArray data = networkReply->readAll();
        QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
        xmlReader.addData(codec->toUnicode(data));
        parseXml();
    }
}

void Bash::parseXml()
{
    int c = 0;
    while (!xmlReader.atEnd() && c < 10)
    {
        xmlReader.readNext();
        if (xmlReader.isStartElement())
        {
            if (xmlReader.name() == "item")
            {
                while (!xmlReader.atEnd() && c < 10)
                {
                    xmlReader.readNext();
                    QStringRef token = xmlReader.name();
                    if (xmlReader.isStartElement() && (token == "title" || token == "pubDate"))
                    {
                        xmlReader.readNext();
                        textEdit->textCursor().insertHtml("<b>" + xmlReader.text().toString() + "<b><br>");
                    }
                    if (xmlReader.isCDATA())
                    {
                        textEdit->textCursor().insertHtml(xmlReader.text().toString() + "<br><br>");
                        c++;
                    }
                }
            }
        }
    }
    if (xmlReader.error() && xmlReader.error() != QXmlStreamReader::PrematureEndOfDocumentError)
    {
        qWarning() << "XML ERROR:" << xmlReader.lineNumber() << ": " << xmlReader.errorString();
    }
}
