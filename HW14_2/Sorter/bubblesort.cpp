#include "bubblesort.h"

void BubbleSort::sort(int ar[], int arlen)
{
    for (int i = 0; i < arlen; i++)
    {
        for (int j = 0; j < arlen - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                int tmp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = tmp;
            }
        }
    }
}
