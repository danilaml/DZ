#include <iostream>
#include <QObject>
#include "dispconsole.h"
#include "dispfile.h"
#include "dispstreamtest.h"

using namespace std;

int main()
{
//    int** ar = new int*[4];
//    ar[0] = new int[4] {1, 2, 3, 4};
//    ar[1] = new int[4] {5, 6, 7, 8};
//    ar[2] = new int[4] {9, 10, 11, 12};
//    ar[3] = new int[4] {13, 14, 15, 16};

    DispStreamTest dpstest ;
    QTest::qExec(&dpstest);

    std::cout << endl;

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

    cout << "Enter 'f' to use DispFile or 'c' to use DispConsole" << endl;
    char c;
    cin >> c;
    switch (c)
    {
    case 'f':
    {
        Displayer* dispf = new DispFile();
        dispf->display(ar, n);
        delete dispf;
        break;
    }
    case 'c':
    {
        Displayer* dispc = new DispConsole();
        dispc->display(ar, n);
        delete dispc;
        break;
    }
    default:
        cout << "Incorrect parameters";
    }

    for (int i = 0; i < n; i++)
        delete[] ar[i];
    delete[] ar;

    return 0;
}

