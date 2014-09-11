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
        MyTVector<4> mtv({1, 2, 3});
        MyTVector<4> copy(mtv);

        QCOMPARE(mtv, copy);
    }

    void isNullVectorTest()
    {
        MyTVector<3> mtvf({1, 2, 3});
        QVERIFY(!mtvf.isNullVector());

        MyTVector<3> mtvs({0, 0, 0});
        QVERIFY(mtvs.isNullVector());
    }

    void scalarProductTest()
    {
        MyTVector<3> mtv({1, 2, 3});
        QCOMPARE(mtv.scalarProduct(mtv), 14);
    }

    void equalsTest()
    {
        MyTVector<5> mtv({1, 2, 3, 4, 5});

        QVERIFY(mtv == mtv);
    }

    void plusminTest()
    {
        MyTVector<3> mtvf({1, 2, 3});
        MyTVector<3> mtvs({0, 2, 0});

        QCOMPARE(mtvf + mtvs, (MyTVector<3>({1, 4, 3})));
        QCOMPARE(mtvf - mtvs, (MyTVector<3>({1, 0, 3})));
    }

};

#endif // MYTVECTORTEST_H
