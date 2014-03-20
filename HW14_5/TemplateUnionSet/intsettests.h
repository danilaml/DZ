#ifndef SETTESTS_H
#define SETTESTS_H

#include <QObject>
#include <QtTest/QtTest>
#include "myset.h"

class IntSetTests : public QObject
{
    Q_OBJECT
public:
    explicit IntSetTests(QObject *parent = 0);

private slots:
    void initTestCase()
    {
        ms = new MySet<int>();
    }

    void testAdd()
    {
        ms->add(1);
        QVERIFY(ms->contains(1));
    }

    void testDelete()
    {
        ms->add(1);
        ms->del(1);
        QVERIFY(!ms->contains(1));
    }

    void testUnion()
    {
        MySet<int> tmp;
        tmp.add(3);
        tmp.add(4);
        ms->add(2);
        ms->add(3);
        tmp = ms->unite(tmp);
        QVERIFY(tmp.contains(2) && tmp.contains(3) && tmp.contains(4));
    }

    void testIntersect()
    {
        MySet<int> tmp;
        tmp.add(3);
        tmp.add(4);
        tmp = ms->intersect(tmp);
        QVERIFY(!tmp.contains(2) && tmp.contains(3) && !tmp.contains(4));
    }

    void cleanupTestCase()
    {
        delete ms;
    }

private:
    MySet<int> *ms;

};

#endif // SETTESTS_H
