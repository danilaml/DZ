#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "exprcalculator.h"
#include <QSignalMapper>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    signalMapper = new QSignalMapper(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButton_0, "0");
    connect(ui->pushButton_1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButton_1, "1");
    connect(ui->pushButton_2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButton_2, "2");
    connect(ui->pushButton_3, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButton_3, "3");
    connect(ui->pushButton_4, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButton_4, "4");
    connect(ui->pushButton_5, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButton_5, "5");
    connect(ui->pushButton_6, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButton_6, "6");
    connect(ui->pushButton_7, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButton_7, "7");
    connect(ui->pushButton_8, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButton_8, "8");
    connect(ui->pushButton_9, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButton_9, "9");
    connect(ui->pushButton_plus, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButton_plus, "+");
    connect(ui->pushButton_minus, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButton_minus, "-");
    connect(ui->pushButton_mult, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButton_mult, "*");
    connect(ui->pushButton_div, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButton_div, "/");
    connect(ui->pushButton_dot, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->pushButton_dot, ".");

    connect(signalMapper, SIGNAL(mapped(const QString&)), this, SLOT(exprEntered(const QString&)));
    connect(ui->pushButton_eql, SIGNAL(clicked()), this, SLOT(calcExpr()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exprEntered(const QString &text)
{
    if(text[0] < '0')
    {
        QString res = ui->lineEdit->text();
        if((res.length() > 0) && (res[res.length() - 1] < '0'))
        {
            res[res.length() - 1] = text[0];
            ui->lineEdit->setText(res);
        }
        else
        {
            if(res[res.length() - 1] >= 'a')
            {
                return;
            }
            else
            {
                ui->lineEdit->setText(ui->lineEdit->text() + text);
            }
        }
    }
    else
    {
        QString res = ui->lineEdit->text();
        if((res.length() > 0) && ((res[res.length() - 1] >= 'a') || res[0] == '0'))
        {
            ui->lineEdit->setText(text);
        }
        else
        {
            ui->lineEdit->setText(ui->lineEdit->text() + text);
        }
    }
}

void MainWindow::calcExpr()
{
    QString res = ui->lineEdit->text();
    if((res.length() == 0) || (res[0] == 'i') || (res[0] == 'n'))
    {
        return;
    }
    res.setNum(ExprCalculator::calculateExpr(res));
    ui->lineEdit->setText(res);
}
