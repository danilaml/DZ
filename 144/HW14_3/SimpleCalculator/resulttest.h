#ifndef RESULTTEST_H
#define RESULTTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "result.h"

class ResultTest : public QObject
{
    Q_OBJECT
public:
    explicit ResultTest(QObject *parent = 0);

private slots:
    void testRecalculateSum()
    {
        QCOMPARE(Result::recalculate(1, 5, 0), QString("6"));
    }

    void testRecalculateDivision()
    {
        QCOMPARE(Result::recalculate(10, 2, 3), QString("5"));
    }

};

#endif // RESULTTEST_H
