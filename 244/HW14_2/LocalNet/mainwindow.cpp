#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLineEdit"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	step(0)
{
	ui->setupUi(this);
	ui->spinBox->findChild<QLineEdit*>()->setReadOnly(true);

	number = 5;
	pcs = QVector<GenericPC*>(number);

	pcs[0] = new GenericPC(true, 0.75, 0, "Windows");
	pcs[1] = new GenericPC(false, 0.25, 1, "Linux");
	pcs[2] = new GenericPC(false, 0.75, 2, "Windows");
	pcs[3] = new GenericPC(false, 0.25, 3, "Linux");
	pcs[4] = new GenericPC(false, 0.35, 4, "OSX");

	netTop = QVector< QVector<bool> >(number, QVector<bool>(number, false));
	firstInf = QVector<bool>(number, false);
	infected = QVector<bool>(number, false);

	netTop[0][1] = true;
	netTop[1][2] = true;
	netTop[2][3] = true;
	netTop[3][4] = true;
	netTop[1][4] = true;

	timer = new QTimer(this);
	timer->stop();
	connect(timer, SIGNAL(timeout()), this, SLOT(updateCount()));
	for (GenericPC* p : pcs)
	{
		p->setTimer(timer);
		if (p->isInfected)
		{
			firstInf[p->id] = true;
			connect(timer, SIGNAL(timeout()), p, SLOT(infect()));
		}
		connect(p, SIGNAL(infected(int)), this, SLOT(newPcInfected(int)));
	}
}

MainWindow::~MainWindow()
{
	delete ui;
	for (uint i = 0; i < number; i++)
	{
		delete pcs[i];
	}
	delete timer;
}

void MainWindow::updateCount()
{
	this->setWindowTitle(QString("LocalNet: шаг ") + QString::number(step));
	step++;
}

void MainWindow::on_pushButton_clicked()
{
	if (ui->pushButton->text().length() == 6)
	{
		ui->pushButton_2->setEnabled(true);
	}
	if (ui->pushButton->text().length() != 5)
	{
		timer->start(1000 * ui->spinBox->value());
		ui->pushButton->setText("Пауза");
	}
	else
	{
		timer->stop();
		ui->pushButton->setText("Продолжить");
	}
}

void MainWindow::on_pushButton_2_clicked()
{
	ui->pushButton_2->setEnabled(false);
	timer->stop();
	step = 0;
	this->setWindowTitle(QString("LocalNet: шаг 0"));
	ui->pushButton->setText("Старт!");
	infected.fill(false);
	ui->plainTextEdit->setPlainText("");
	for (GenericPC* p : pcs)
	{
		if (!firstInf[p->id])
		{
			p->isInfected = false;
			disconnect(timer, SIGNAL(timeout()), p, SLOT(infect()));
		}
	}
}

void MainWindow::newPcInfected(int id)
{
	if (!infected[id])
	{
		(ui->plainTextEdit->textCursor().insertText(QString("ПК номер %1 на %2 заражён! "
															"Шаг: %3\n").arg(id).arg(pcs[id]->os).arg(step - 1)));
		infected[id] = true;
	}
	for (uint i = 0; i < number; i++)
	{
		if (!pcs[i]->isInfected && netTop.at(id).at(i))
			connect(timer, SIGNAL(timeout()), pcs[i], SLOT(throwDice()));
	}
}
