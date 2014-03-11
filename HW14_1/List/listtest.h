#ifndef LISTTEST_H
#define LISTTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "mylinkedlist.h"
#include "mydoublelinkedlist.h"

class ListTest : public QObject
{
    Q_OBJECT
public:
    explicit ListTest(QObject *parent = 0);

private slots:
    void initTestCase()
    {
        mll = new MyLinkedList();
        mdl = new MyDoubleLinkedList();
    }

    void testEmptyLinkedList()
    {
        QVERIFY(mll->length() == 0);
    }

    void testEmptyDoubleLinkedList()
    {
        QVERIFY(mdl->length() == 0);
    }

    void testGetElementFromEmptyLinkedList()
    {
        QVERIFY(mll->getElementAt(0) == INT_MIN);
    }

    void testGetElementFromEmptyDoubleLinkedList()
    {
        QVERIFY(mdl->getElementAt(0) == INT_MIN);
    }

    void testLinkedListInsert()
    {
        mll->insert(1, 0);
        QVERIFY(mll->length() == 1);
    }

    void testLinkedDoubleListInsert()
    {
        mdl->insert(1, 0);
        QVERIFY(mdl->length() == 1);
    }

    void testLinkedListDelete()
    {
        mll->insert(1,0);
        QVERIFY(mll->deleteElementAt(0));
    }

    void testDoubleLinkedListDelete()
    {
        mdl->insert(1,0);
        QVERIFY(mdl->deleteElementAt(0));
    }

    void cleanupTestCase()
    {
        delete mll;
        delete mdl;
    }

private:
    MyLinkedList *mll;
    MyDoubleLinkedList *mdl;

};

#endif // LISTTEST_H
