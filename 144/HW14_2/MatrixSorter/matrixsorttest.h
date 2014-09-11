#ifndef MATRIXSORTTEST_H
#define MATRIXSORTTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "matrixquicksort.h"

class MatrixSortTest : public QObject
{
    Q_OBJECT
public:
    explicit MatrixSortTest(QObject *parent = 0);

private slots:
    void initTestCase()
    {
        mqs = new MatrixQuickSort();
    }

    void testSorting()
    {
        int** ar = new int*[4];
        ar[0] = new int[4] {5, 6, 7, 8};
        ar[1] = new int[4] {1, 2, 3, 4};
        ar[2] = new int[4] {32, 10, 11, 12};
        ar[3] = new int[4] {13, 14, 15, 16};

        mqs->sort(ar, 4);
        QVERIFY(isSorted(ar, 4));

        for (int i = 0; i < 4; i++)
            delete[] ar[i];
        delete[] ar;
    }

    void cleanupTestCase()
    {
        delete mqs;
    }

private:
    bool isSorted(int** ar, int arlen)
    {
        for (int i = 0; i < arlen - 1; i++)
        {
            if(ar[i][0] > ar[i + 1][0]) return false;
        }
        return true;
    }

    MatrixQuickSort *mqs;
};

#endif // MATRIXSORTTEST_H
