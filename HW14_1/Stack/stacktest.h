#ifndef STACKTEST_H
#define STACKTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "myarraystack.h"
#include "mylinkedstack.h"

class StackTest : public QObject
{
    Q_OBJECT
public:
    explicit StackTest(QObject *parent = 0);

private slots:
    void initTestCase()
    {
        mas = new MyArrayStack();
        mls = new MyLinkedStack();
    }

    void testEmptyArrayStack()
    {
        QVERIFY(mas->size() == 0);
    }

    void testEmptyLinkedStack()
    {
        QVERIFY(mls->size() == 0);
    }

    void testPopFromEmptyArrayStack()
    {
        QVERIFY(mas->pop() == INT_MIN);
    }

    void testPopFromEmptyLinkedStack()
    {
        QVERIFY(mls->pop() == INT_MIN);
    }

    void testArrayPush()
    {
        mas->push(1);
        QVERIFY(mas->size() == 1);
    }

    void testLinkedPush()
    {
        mls->push(1);
        QVERIFY(mls->size() == 1);
    }

    void testArrayPop()
    {
        mas->push(2);
        QVERIFY(mas->pop() == 2);
    }

    void testLinkedPop()
    {
        mls->push(2);
        QVERIFY(mls->pop() == 2);
    }

    void cleanupTestCase()
    {
        delete mas;
        delete mls;
    }

private:
    MyArrayStack *mas;
    MyLinkedStack *mls;
};

#endif // STACKTEST_H
