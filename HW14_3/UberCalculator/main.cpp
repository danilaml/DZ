#include "mainwindow.h"
#include <QApplication>
#include "exprcalculatortest.h"

int main(int argc, char *argv[])
{
    ExprCalculatorTest exprclctest;
    QTest::qExec(&exprclctest);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
