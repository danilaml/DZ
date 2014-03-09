#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include "result.h"

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
    ui->lineEdit->setText(Result::recalculate(arg1, ui->spinBox_2->value(), ui->comboBox->currentIndex()));
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->lineEdit->setText(Result::recalculate(ui->spinBox->value(), ui->spinBox_2->value(), index));
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    ui->lineEdit->setText(Result::recalculate(ui->spinBox->value(), arg1, ui->comboBox->currentIndex()));
}
