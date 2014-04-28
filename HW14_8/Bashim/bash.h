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

class Bash : public QDialog
{
    Q_OBJECT

public:
    explicit Bash(QWidget *parent = 0);
    ~Bash();

private slots:
    void requestQuotes();
    void replyFinished(QNetworkReply *reply);

private:
    Ui::Bash *ui;
    QTextEdit *textEdit;
    QPushButton *loadButton;
    QPushButton *quitButton;
    QNetworkAccessManager *manager;
    QNetworkReply *networkReply;
    QXmlStreamReader xmlReader;
};

#endif // BASH_H
