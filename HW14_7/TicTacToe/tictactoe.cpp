#include "tictactoe.h"
#include "ui_tictactoe.h"
#include <QGridLayout>
#include <QMessageBox>

TicTacToe::TicTacToe(QWidget *parent) :
    QWidget(parent),
    state(QVector<QVector<states>>(3, QVector<states>(3))),
    buttons(QVector<QPushButton*>(3 * 3)),
    boardSize(3),
    turn(0)
{
    ui->setupUi(this);

    qsm = new QSignalMapper(this);

    QGridLayout *mainLayout = new QGridLayout();
    for (int i = 0; i < 3 * 3; i++)
    {
        state[i % 3][i / 3] = Nothing;
        QPushButton *tmp = new QPushButton(" ", this);
        buttons[i] = tmp;
        tmp->setMinimumSize(30, 30);
        QFont font = tmp->font();
        font.setPointSize(16);
        tmp->setFont(font);
        tmp->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        connect(tmp, SIGNAL(clicked()), qsm, SLOT(map()));
        qsm->setMapping(tmp, i);
        mainLayout->addWidget(tmp, i % 3, i / 3);
    }

    connect(qsm, SIGNAL(mapped(int)), this, SLOT(stateChanged(int)));

    setLayout(mainLayout);
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

    qsm = new QSignalMapper(this);

    QGridLayout *mainLayout = new QGridLayout();
    for (int i = 0; i < bSize * bSize; i++)
    {
        state[i % bSize][i / bSize] = Nothing;
        QPushButton *tmp = new QPushButton(" ", this);
        buttons[i] = tmp;

        tmp->setMinimumSize(30, 30);
        QFont font = tmp->font();
        font.setPointSize(16);
        tmp->setFont(font);
        tmp->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

        connect(tmp, SIGNAL(clicked()), qsm, SLOT(map()));
        qsm->setMapping(tmp, i);
        mainLayout->addWidget(tmp, i % bSize, i / bSize);
    }

    connect(qsm, SIGNAL(mapped(int)), this, SLOT(stateChanged(int)));

    setLayout(mainLayout);
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
            QMessageBox msgBox;
            msgBox.setWindowTitle(turn % 2 == 0 ? "X won!" : "O won!");
            msgBox.setText("Congratulations!");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
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
    state = QVector<QVector<states>>(sz, QVector<states>(sz));
    buttons = QVector<QPushButton*>(sz * sz);

    qsm = new QSignalMapper(this);

    QGridLayout *mainLayout = new QGridLayout();
    for (int i = 0; i < sz * sz; i++)
    {
        state[i % sz][i / sz] = Nothing;
        QPushButton *tmp = new QPushButton(" ", this);
        buttons[i] = tmp;

        tmp->setMinimumSize(30, 30);
        QFont font = tmp->font();
        font.setPointSize(16);
        tmp->setFont(font);
        tmp->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

        connect(tmp, SIGNAL(clicked()), qsm, SLOT(map()));
        qsm->setMapping(tmp, i);
        mainLayout->addWidget(tmp, i % sz, i / sz);
    }

    connect(qsm, SIGNAL(mapped(int)), this, SLOT(stateChanged(int)));

    setLayout(mainLayout);
}

bool TicTacToe::checkForWin(int i, int j) const
{
    states current = state[i][j];
    if ((i + 2) < boardSize && current == state[i + 1][j] && current == state[i + 2][j])
        return true;
    else if ((i + 1) < boardSize && (i - 1) >= 0 && state[i - 1][j] == current && current == state[i + 1][j])
        return true;
    else if ((i - 2) >= 0 && state[i - 2][j] == current && current == state[i - 1][j])
        return true;
    else if ((j + 2) < boardSize && state[i][j + 1] == current  && current == state[i][j + 2])
        return true;
    else if ((j + 1) < boardSize && (j - 1) >= 0 && state[i][j - 1] == current && current == state[i][j + 1])
        return true;
    else if ((j - 2) >= 0 && state[i][j - 2] == current && current == state[i][j - 1])
        return true; // Vertical and horizontal cases
    else if ((i + 2) < boardSize && (j + 2) < boardSize && current == state[i + 1][j + 1] && current == state[i + 2][j + 2])
        return true;
    else if ((i + 1) < boardSize && (j + 1) < boardSize && (i - 1) >= 0 && (j - 1) >= 0 &&
             state[i - 1][j - 1] == current && current == state[i + 1][j + 1])
        return true;
    else if ((i - 2) >= 0 && (j - 2) >= 0 && state[i - 2][j - 2] == current && current == state[i - 1][j - 1])
        return true;
    else if ((i - 2) >= 0 && (j + 2) < boardSize && state[i - 1][j + 1] == current && current == state[i - 2][j + 2])
        return true;
    else if ((i - 1) >= 0 && (j - 1) >= 0 && (i + 1) < boardSize && (j + 1) < boardSize && state[i - 1][j + 1] == current && current == state[i + 1][j - 1])
        return true;
    else if ((i + 2) < boardSize && (j - 2) >= 0 && state[i + 1][j - 1] == current && current == state[i + 2][j - 2])
        return true; // diagonal cases
    else
        return false;
}
