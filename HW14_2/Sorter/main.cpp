#include <iostream>
#include "sorter.h"
#include "bubblesort.h"
#include "quicksort.h"

using namespace std;

void printAr(int ar[], int arlen);

int main()
{
    int arrb[5] = {5, 4, 3, 2, 1};
    Sorter* srtb = new BubbleSort();

    printAr(arrb, 5);
    srtb->sort(arrb, 5);
    printAr(arrb, 5);

    cout << endl;

    int arrq[7] = {5, 4, 6, 8, 3, 2, 1};
    Sorter* srtq = new QuickSort();

    printAr(arrq, 7);
    srtq->sort(arrq, 7);
    printAr(arrq, 7);

    return 0;
}

void printAr(int ar[], int arlen)
{
    for (int i = 0; i < arlen; i++)
    {
        cout << ar[i] << ((i == arlen - 1) ? "\n" : " : ");
    }
}

