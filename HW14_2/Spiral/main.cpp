#include <iostream>
#include "dispconsole.h"
#include "dispfile.h"

using namespace std;

int main()
{
//    int** ar = new int*[3];
//    ar[0] = new int[3] {1, 2, 3};
//    ar[1] = new int[3] {4, 5, 6};
//    ar[2] = new int[3] {7, 8, 9};
    int** ar = new int*[4];
    ar[0] = new int[4] {1, 2, 3, 4};
    ar[1] = new int[4] {5, 6, 7, 8};
    ar[2] = new int[4] {9, 10, 11, 12};
    ar[3] = new int[4] {13, 14, 15, 16};
    Displayer* dispc = new DispConsole();
    Displayer* dispf = new DispFile();

    dispc->display(ar, 4);
    dispf->display(ar, 4);

    return 0;
}

