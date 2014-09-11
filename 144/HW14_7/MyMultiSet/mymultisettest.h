#ifndef MYMULTISETTEST_H
#define MYMULTISETTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "mymultiset.h"

/// Tests fo MyMutiSet with int as template parameter
class MyMultiSetTest : public QObject
{
    Q_OBJECT
public:
    explicit MyMultiSetTest(QObject *parent = 0);

private slots:

    void testAdd()
    {
        MyMultiSet<int> mms;
        mms.add(1);
        QVERIFY(mms.contains(1));
    }

    void testDelete()
    {
        MyMultiSet<int> mms;

        mms.add(1);
        mms.add(2);
        mms.del(1);
        QVERIFY(!mms.contains(1) && mms.contains(2));

        mms.add(2);
        mms.del(2);
        QVERIFY(mms.contains(2));
    }

    void testSize()
    {
        MyMultiSet<int> mms;
        mms.add(1);
        mms.add(1);
        mms.add(2);
        QVERIFY(mms.size() == 3);
    }

};

#endif // MYMULTISETTEST_H
