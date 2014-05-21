#ifndef COMPARATORTEST_H
#define COMPARATORTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "bubblesort.h"
#include "standardcomparator.h"
#include "reversecomparator.h"

/// Tests standard and reverse comparators with int and double as parametr
class ComparatorTest : public QObject
{
    Q_OBJECT
public:
    explicit ComparatorTest(QObject *parent = 0);

private slots:
    void standardIntTest()
    {
        StandardComparator<int> standCmp;
        BubbleSort<int> bblSrt;
        int ar[6] = {3, 4, 5, 2, 0, 1};
        bblSrt.sort(ar, 6, standCmp);
        int sorted[6] = {0, 1, 2, 3, 4, 5};
        QVERIFY(isEqual<int>(ar, sorted, 6));
    }

    void standardDoubleTest()
    {
        StandardComparator<double> standCmp;
        BubbleSort<double> bblSrt;
        double ar[6] = {3.0, 4.0, 5.0, 2.0, 0.0, 1.0};
        bblSrt.sort(ar, 6, standCmp);
        double sorted[6] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
        QVERIFY(isEqual<double>(ar, sorted, 6));
    }

    void reverseTest()
    {
        ReverseComparator<int> revCmp;
        BubbleSort<int> bblSrt;
        int ar[6] = {3, 4, 5, 2, 0, 1};
        bblSrt.sort(ar, 6, revCmp);
        int sorted[6] = {5, 4, 3, 2, 1};
        QVERIFY(isEqual<int>(ar, sorted, 6));
    }

    void reverseDoubleTest()
    {
        ReverseComparator<double> revCmp;
        BubbleSort<double> bblSrt;
        double ar[6] = {3.0, 4.0, 5.0, 2.0, 0.0, 1.0};
        bblSrt.sort(ar, 6, revCmp);
        double sorted[6] = {5.0, 4.0, 3.0, 2.0, 1.0, 0.0};
        QVERIFY(isEqual<double>(ar, sorted, 6));
    }

private:
    template<typename T>
    bool isEqual(T arl[], T arr[], int arlen)
    {
        for (int i = 0; i < arlen - 1; i++)
        {
            if(arl[i] != arr[i]) return false;
        }
        return true;
    }
};

#endif // COMPARATORTEST_H
