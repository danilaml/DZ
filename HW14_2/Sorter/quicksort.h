#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "sorter.h"

class QuickSort : public Sorter
{
public:
    /// QuckSort implementation of Sorter interface
    void sort(int ar[], int arlen);
};

#endif // QUICKSORT_H
