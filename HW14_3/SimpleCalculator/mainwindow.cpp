#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    recalculate(arg1, ui->spinBox_2->value(), ui->comboBox->currentIndex());
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    recalculate(ui->spinBox->value(), ui->spinBox_2->value(), index);
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    recalculate(ui->spinBox->value(), arg1, ui->comboBox->currentIndex());
}

void MainWindow::recalculate(int larg, int rarg, int actionIndex)
{
    QString res = "";
    switch (actionIndex)
    {
    case 0:
        res.setNum(larg + rarg);
        break;
    case 1:
        res.setNum(larg - rarg);
        break;
    case 2:
        res.setNum(larg * rarg);
        break;
    case 3:
        (rarg == 0) ? (res = "DvZ") : res.setNum(larg / rarg);
        break;
    }

    ui->lineEdit->setText(res);
}
