#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <QSignalMapper>
#include <QGridLayout>

namespace Ui {
class TicTacToe;
}

/// Widget that handles n x n tictactoe board
class TicTacToe : public QWidget
{
    Q_OBJECT

public:
    explicit TicTacToe(QWidget *parent = 0);
    explicit TicTacToe(int bSize, QWidget *parent = 0);
    ~TicTacToe();

signals:
    void newTurn(int trn);

private slots:
    void stateChanged(int pos);
    void restart();
    void resizeBoard(int sz);

private:
    bool checkForWin(int i, int j) const;
    bool checkVerticalHorizontal(int i, int j, int len) const;
    bool checkDiagonal(int i, int j, int len) const;
    /// Shows MessageBox with
    /// @param title title and @param text text
    void showMsgBox(QString const &title, QString const &text);
    /// Places boardSize^2 buttons onto layout.
    void setupButtons();

    enum states { Nothing, Cross, Naught };
    Ui::TicTacToe *ui;
    QVector<QVector<states>> state;
    QVector<QPushButton*> buttons;
    QSignalMapper *qsm;
    int boardSize;
    int turn;
};

#endif // TICTACTOE_H
