#ifndef UNIQUELISTTEST_H
#define UNIQUELISTTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include <iostream>
#include "myuniquelist.h"

class UniqueListTest : public QObject
{
    Q_OBJECT
public:
    explicit UniqueListTest(QObject *parent = 0);

private slots:
    void initTestCase()
    {
        mul = new MyUniqueList();
    }

    void testEmptyUniqueList()
    {
        QVERIFY(mul->length() == 0);
    }

    void testGetElementFromEmptyLinkedList()
    {
        try
        {
            mul->getElementAt(0);
        }
        catch (const MyException &exec)
        {
            QCOMPARE(exec.message, "Can't get element, list is empty");
        }
    }

    void testUniqueListInsert()
    {
        try
        {
            mul->insert(1, 0);
        }
        catch (const MyException &exec)
        {
            std::cout << exec.message << std::endl;
        }

        QVERIFY(mul->length() == 1);
    }

    void testUniqueListDelete()
    {
        try
        {
            mul->insert(2,0);
            mul->deleteElementAt(0);
        }
        catch (const MyException &exec)
        {
            std::cout << exec.message << std::endl;
        }

        QVERIFY(!mul->contains(2));
    }

    void cleanupTestCase()
    {
        delete mul;
    }

private:
    MyUniqueList *mul;

};

#endif // UNIQUELISTTEST_H
