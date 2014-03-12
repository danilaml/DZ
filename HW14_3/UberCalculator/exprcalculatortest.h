#ifndef EXPRCALCULATORTEST_H
#define EXPRCALCULATORTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "exprcalculator.h"

class ExprCalculatorTest : public QObject
{
    Q_OBJECT
public:
    explicit ExprCalculatorTest(QObject *parent = 0);

private slots:
    void testCalculation()
    {
        QString testexpr = "1+9*50-40/80";
        QCOMPARE(ExprCalculator::calculateExpr(testexpr), 446.5);
    }

};

#endif // EXPRCALCULATORTEST_H
