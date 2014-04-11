#ifndef MYTVECTORTEST_H
#define MYTVECTORTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "mytvector.h"

/// Unit tests for MyTVector
class MyTVectorTest : public QObject
{
    Q_OBJECT
public:
    explicit MyTVectorTest(QObject *parent = 0);

private slots:

    void copyTest()
    {
        MyTVector<int, 4> mtv({1, 2, 3});
        MyTVector<int, 4> copy(mtv);

        QCOMPARE(mtv, copy);
    }

    void isNullVectorTest()
    {
        MyTVector<int, 3> mtvf({1, 2, 3});
        QVERIFY(!mtvf.isNullVector());

        MyTVector<int, 3> mtvs({0, 0, 0});
        QVERIFY(mtvs.isNullVector());
    }

    void scalarProductTest()
    {
        MyTVector<int, 3> mtv({1, 2, 3});
        QCOMPARE(mtv.scalarProduct(mtv), 14);
    }

    void equalsTest()
    {
        MyTVector<int, 5> mtv({1, 2, 3, 4, 5});

        QVERIFY(mtv == mtv);
    }

    void plusminTest()
    {
        MyTVector<int, 3> mtvf({1, 2, 3});
        MyTVector<int, 3> mtvs({0, 2, 0});

        QCOMPARE(mtvf + mtvs, (MyTVector<int, 3>({1, 4, 3})));
        QCOMPARE(mtvf - mtvs, (MyTVector<int, 3>({1, 0, 3})));
    }

};

#endif // MYTVECTORTEST_H
