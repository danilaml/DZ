#include "mainwindow.h"
#include <QApplication>
#include "resulttest.h"

int main(int argc, char *argv[])
{
    ResultTest rstest;
    QTest::qExec(&rstest);

    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(w.size());
    w.show();

    return a.exec();
}
