#include <iostream>
#include "matrixquicksort.h"
#include "matrixsorttest.h"

using namespace std;

void printAr(int ar[], int arlen);

int main()
{
    MatrixSortTest mstest;
    QTest::qExec(&mstest);

    cout << endl;

    int n = 0;
    cout << "Enter number of columns: ";
    cin >> n;
    int** ar = new int*[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter column #" << i << endl;
        int* tmp = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> tmp[j];
        }
        ar[i] = tmp;
    }
    MatrixQuickSort* mqs = new MatrixQuickSort();
    mqs->sort(ar, n);

    for (int i = 0; i < n; i++)
    {
        printAr(ar[i], n);
    }

    for (int i = 0; i < n; i++)
        delete[] ar[i];
    delete[] ar;
    delete mqs;

    return 0;
}

void printAr(int ar[], int arlen)
{
    for (int i = 0; i < arlen; i++)
    {
        cout << ar[i] << ((i == arlen - 1) ? "\n" : " : ");
    }
}

