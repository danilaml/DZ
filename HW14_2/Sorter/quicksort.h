#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "sorter.h"

class QuickSort : public Sorter
{
public:
    void sort(int ar[], int arlen);
};

#endif // QUICKSORT_H
