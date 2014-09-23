#include "mainwindow.h"
#include <QApplication>
#include "localnettest.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	LocalNetTest lcnt;
	QTest::qExec(&lcnt);

	MainWindow w;
	w.show();

	return a.exec();
}
