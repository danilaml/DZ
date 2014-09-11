#ifndef BASH_H
#define BASH_H

#include <QDialog>
#include <QtNetwork/QtNetwork>
#include <QTextEdit>
#include <QPushButton>
#include <QXmlStreamReader>

namespace Ui {
class Bash;
}

/// Simple Widget that can load last ten bash.im (.org.ru) quotes
class Bash : public QDialog
{
    Q_OBJECT

public:
    explicit Bash(QWidget *parent = 0);
    ~Bash();

private slots:
    void requestQuotes();
    void replyFinished(QNetworkReply *reply);
    void slotReadyRead();

private:
    void parseXml();

    Ui::Bash *ui;
    QTextEdit *textEdit;
    QPushButton *loadButton;
    QPushButton *quitButton;
    QNetworkAccessManager *manager;
    QNetworkReply *networkReply;
    QXmlStreamReader xmlReader;
};

#endif // BASH_H
