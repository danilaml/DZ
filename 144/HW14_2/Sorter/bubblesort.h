#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "sorter.h"

class BubbleSort : public Sorter
{
public:
    /// BubbleSort implementation of Sorter interface
    void sort(int ar[], int arlen);
};

#endif // BUBBLESORT_H
