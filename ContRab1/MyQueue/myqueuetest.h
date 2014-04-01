#ifndef MUQUEUETEST_H
#define MUQUEUETEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "myqueue.h"

/// Unit tests for MyQueue
class MyQueueTest : public QObject
{
    Q_OBJECT
public:
    explicit MyQueueTest(QObject *parent = 0);

private slots:

    void enqueueTest()
    {
        MyQueue<int> mq;
        mq.enqueue(1, 1);
        mq.enqueue(2, 0);

        QVERIFY(mq.contains(1));
        QVERIFY(mq.contains(2));
    }

    void dequeueTest()
    {
        MyQueue<int> mq;
        mq.enqueue(1, 1);
        mq.enqueue(2, 0);

        try
        {
            QVERIFY(mq.dequeue() == 1);
            QVERIFY(mq.dequeue() == 2);
        }
        catch (MyEmptyException)
        {
            QFAIL("Exception in dequeue");
        }

        try
        {
            mq.dequeue();
            QFAIL("No exception thrown with empty queue");
        }
        catch (MyEmptyException)
        {

        }
        catch (...)
        {
            QFAIL("Unexpected exception");
        }

    }
};

#endif // MUQUEUETEST_H
