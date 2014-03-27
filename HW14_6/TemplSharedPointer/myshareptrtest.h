#ifndef MYSHAREPTRTEST_H
#define MYSHAREPTRTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "mysharedpointer.h"
#include <iostream>

class MySharePtrTest : public QObject
{
    Q_OBJECT
public:
    explicit MySharePtrTest(QObject *parent = 0);

private slots:
    void initTestCase()
    {
        msp = new MySharedPointer<int>(new int(13));
    }

    void copyTest()
    {
        MySharedPointer<int> tmp(*msp);
        QVERIFY(*(msp->get()) == 13);
        QVERIFY(msp->useCount() == 2);
    }

    void assignTest()
    {
        MySharedPointer<int> tmp(new int(88));
        *msp = tmp;
        QCOMPARE(tmp.get(), msp->get());
        QVERIFY(tmp.useCount() == 2);
    }

    void cleanupTestCase()
    {
        MySharedPointer<int> tmp(*msp);
        int count = tmp.useCount();
        delete msp;
        QVERIFY(tmp.useCount() == count - 1);
    }

private:
    MySharedPointer<int> *msp;

};

#endif // MYSHAREPTRTEST_H
