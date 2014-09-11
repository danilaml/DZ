#include "mquicksort.h"

void qsort(int ar[], int low, int high)
{
    int i, j, m, tmp;
    i = low;
    j = high;
    m = ar[(i + j) / 2];
    do
    {
      while (ar[i] < m)
          i++;
      while (ar[j] > m)
          j--;
      if (i <= j)
      {
          tmp = ar[i];
          ar[i] = ar[j];
          ar[j] = tmp;
          i++;
          j--;
      }
    } while (i <= j);
    if (low < j)
        qsort(ar, low, j);
    if (i < high)
        qsort(ar, i, high);
}

void QuickSort::sort(int ar[], int arlen)
{
    qsort(ar, 0, arlen - 1);
}
