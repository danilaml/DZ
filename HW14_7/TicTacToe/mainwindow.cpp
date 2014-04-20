#include <QGridLayout>
#include <QMenuBar>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tictactoe.h"
#include "sizedialog.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("TicTacToe. 3x3, turn: 0");

    TicTacToe *ttt = new TicTacToe(3, this);
    setCentralWidget(ttt);

    connect(ttt, SIGNAL(newTurn(int)), this, SLOT(turnChanged(int)));
    connect(this, SIGNAL(boardSizeChanged(int)), ttt, SLOT(resizeBoard(int)));

    QMenu *menuO = new QMenu("Options", this);
    menuO->addAction("Change board size", this, SLOT(changeBoardSize()));
    menuO->addAction("Restart", ttt, SLOT(restart()));

    menuBar()->addMenu(menuO);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::turnChanged(int turn)
{
    setWindowTitle(windowTitle().replace(21, windowTitle().length() - 21, QString::number(turn)));
}

void MainWindow::changeBoardSize()
{
    SizeDialog *sd = new SizeDialog(this);
    int sz = sd->exec();
    if (sz)
    {
        emit boardSizeChanged(sz);
    }
    setWindowTitle(windowTitle().replace(11, 3, QString::number(sz) + "x" + QString::number(sz)));
}
