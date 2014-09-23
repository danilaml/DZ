#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include "genericpc.h"

namespace Ui {
class MainWindow;
}
/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

public slots:
	void updateCount();

private slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void newPcInfected(uint id);

private:
	Ui::MainWindow *ui;
	QTimer *timer;
	QVector<GenericPC*> pcs;
	QVector< QVector<bool> > netTop;
	QVector<bool> firstInf;
	QVector<bool> infected;
	uint number;
	uint step;
};

#endif // MAINWINDOW_H
