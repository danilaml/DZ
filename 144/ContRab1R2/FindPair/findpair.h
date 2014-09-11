#ifndef FINDPAIR_H
#define FINDPAIR_H

#include <QDialog>
#include <QVector>
#include <QSignalMapper>
#include <QPushButton>

namespace Ui {
class FindPair;
}

/// Widget for fin pair game
class FindPair : public QDialog
{
    Q_OBJECT

public:
    explicit FindPair(QWidget *parent = 0);
    ~FindPair();
    /// Shows MessageBox with
    /// @param title title and @param text text
    void showMsgBox(QString const &title, QString const &text);

private slots:
    /// Slot that is called when button is pressed
    void stateChanged(int buttonPressed);

private:
    Ui::FindPair *ui;
    QVector<QVector<int> > state;
    QVector<QPushButton*> buttons;
    QSignalMapper *qsm;
    int boardSize;
    int lastButton;
    int done;
    bool isCompleted;
};

#endif // FINDPAIR_H
