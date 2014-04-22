#include "tictactoe.h"
#include "ui_tictactoe.h"
#include <QMessageBox>

TicTacToe::TicTacToe(QWidget *parent) :
    QWidget(parent),
    state(QVector<QVector<states>>(3, QVector<states>(3))),
    buttons(QVector<QPushButton*>(3 * 3)),
    boardSize(3),
    turn(0)
{
    ui->setupUi(this);

    setupButtons();
}

TicTacToe::TicTacToe(int bSize, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TicTacToe),
    state(QVector<QVector<states>>(bSize, QVector<states>(bSize))),
    buttons(QVector<QPushButton*>(bSize * bSize)),
    boardSize(bSize),
    turn(0)
{
    ui->setupUi(this);

    setupButtons();
}

TicTacToe::~TicTacToe()
{
    delete ui;
}

void TicTacToe::stateChanged(int pos)
{
     if (buttons[pos]->text().at(0) == ' ')
     {
        buttons[pos]->setText(turn % 2 == 0 ? "X" : "O");
        state[pos % boardSize][pos / boardSize] = turn % 2 == 0 ? Cross : Naught;
        if (checkForWin(pos % boardSize, pos / boardSize))
        {
            showMsgBox(turn % 2 == 0 ? "X won!" : "O won!", "Congratulations!");
            restart();
            return;
        }
        else if (turn + 1 == boardSize * boardSize)
        {
            showMsgBox("Draw!", "The game will now restart");
            restart();
            return;
        }
        turn++;
        emit newTurn(turn);
     }
}

void TicTacToe::restart()
{
    for (int i = 0; i < boardSize * boardSize; i++)
    {
        state[i % boardSize][i / boardSize] = Nothing;
        buttons[i]->setText(" ");
    }
    turn = 0;
    emit newTurn(0);
}

void TicTacToe::resizeBoard(int sz)
{
    if(sz == boardSize)
        return;

    delete qsm;
    while (!buttons.isEmpty())
    {
        delete buttons.takeFirst();
    }
    delete layout();

    boardSize = sz;
    turn = 0;
    state = QVector<QVector<states>>(boardSize, QVector<states>(boardSize));
    buttons = QVector<QPushButton*>(boardSize * boardSize);

    setupButtons();
}

bool TicTacToe::checkForWin(int i, int j) const
{
      if (checkVerticalHorizontal(i, j, 3))
          return true;
      else return (checkDiagonal(i, j, 3));
}

bool TicTacToe::checkVerticalHorizontal(int i, int j, int len) const
{
    bool res = true;
    states current = state[i][j];

    for (int k = 0; k < len; k++)
    {
        if ((i - len + k + 1 < 0) || (i + k) >= boardSize)
            continue;
        for (int n = - len + k + 1; n < k + 1; n++)
        {
            res = res && state[i + n][j] == current;
        }
        if (res)
            return true;
    } // Checks all posible vertical combinations

    for (int k = 0; k < len; k++)
    {
        if ((j - len + k + 1 < 0) || (j + k) >= boardSize)
            continue;
        for (int n = - len + k + 1; n < k + 1; n++)
        {
            res = res && state[i][j + n] == current;
        }
        if (res)
            return true;
    } // Checks all posible horizontal combinations

    return false;
}


bool TicTacToe::checkDiagonal(int i, int j, int len) const
{
    bool res = true;
    states current = state[i][j];

    for (int k = 0; k < len; k++)
    {
        if ((i - len + k + 1 < 0) || (i + k) >= boardSize ||
                (j - len + k + 1 < 0) || (j + k) >= boardSize)
            continue;
        for (int n = - len + k + 1; n < k + 1; n++)
        {
            res = res && state[i + n][j + n] == current;
        }
        if (res)
            return true;
    } // Checks all posible diagonal combinations from left to right

    for (int k = 0; k < len; k++)
    {
        if ((i - len + k + 1 < 0) || (i + k) >= boardSize ||
                (j - k < 0) || (j + len - k - 1) >= boardSize)
            continue;
        for (int n = - len + k + 1; n < k + 1; n++)
        {
            res = res && state[i + n][j - n] == current;
        }
        if (res)
            return true;
    } // Checks all posible diagonal combinations from right to left

    return false;
}

void TicTacToe::showMsgBox(const QString &title, const QString &text)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void TicTacToe::setupButtons()
{
    qsm = new QSignalMapper(this);

    QGridLayout *mainLayout = new QGridLayout();
    for (int i = 0; i < boardSize * boardSize; i++)
    {
        state[i % boardSize][i / boardSize] = Nothing;
        QPushButton *tmp = new QPushButton(" ", this);
        buttons[i] = tmp;

        tmp->setMinimumSize(30, 30);
        QFont font = tmp->font();
        font.setPointSize(16);
        tmp->setFont(font);
        tmp->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

        connect(tmp, SIGNAL(clicked()), qsm, SLOT(map()));
        qsm->setMapping(tmp, i);
        mainLayout->addWidget(tmp, i % boardSize, i / boardSize);
    }

    connect(qsm, SIGNAL(mapped(int)), this, SLOT(stateChanged(int)));

    setLayout(mainLayout);
}
