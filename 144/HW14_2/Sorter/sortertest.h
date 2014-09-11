#ifndef SORTERTEST_H
#define SORTERTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "bubblesort.h"
#include "quicksort.h"

class SorterTest : public QObject
{
    Q_OBJECT
public:
    explicit SorterTest(QObject *parent = 0);

private slots:
    void initTestCase()
    {
        bs = new BubbleSort();
        qs = new QuickSort();
    }

    void testBubbleSorting()
    {
        int ar[4] = {5, 99, 7, 8};

        bs->sort(ar, 4);
        QVERIFY(isSorted(ar, 4));
    }

    void testQuickSorting()
    {
        int ar[4] = {5, 6, 77, 8};

        qs->sort(ar, 4);
        QVERIFY(isSorted(ar, 4));
    }

    void cleanupTestCase()
    {
        delete bs;
        delete qs;
    }

private:
    bool isSorted(int ar[], int arlen)
    {
        for (int i = 0; i < arlen - 1; i++)
        {
            if(ar[i] > ar[i + 1]) return false;
        }
        return true;
    }

    BubbleSort *bs;
    QuickSort *qs;
};

#endif // SORTERTEST_H
