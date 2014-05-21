#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "abstractcomparator.h"

/// BubbleSort, duh!
template<typename T>
class BubbleSort
{
public:
    /// Sorts array by bubblesort using comparator
    /// @param ar[] - array to be sorted
    /// @param arlen - array length
    /// @param comp - comparator
    void sort(T ar[], int arlen, AbstractComparator<T> &comp);
};

template<typename T>
void BubbleSort<T>::sort(T ar[], int arlen, AbstractComparator<T> &comp)
{
    for (int i = 0; i < arlen; i++)
    {
        for (int j = 0; j < arlen - i - 1; j++)
        {
            if (comp.compare(ar[j], ar[j + 1]) > 0)
            {
                T tmp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = tmp;
            }
        }
    }
}

#endif // BUBBLESORT_H
