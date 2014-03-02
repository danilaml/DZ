#include "dispconsole.h"
#include <iostream>

using namespace std;

void DispConsole::display(int** ar, int arlen)
{
    int i, j, step, steps, c;
    i = j = (arlen / 2) + (arlen % 2) - 1;
    step = 1;
    steps = 1;
    c = 1;
    cout << ar[i][j];

    while (steps < arlen * arlen)
    {
        for (int k = 0; k < c; k++)
        {
            if (steps == arlen * arlen)
                break;
            cout << " : " << ar[i + step][j];
            i += step;
            steps++;
        }
        for (int k = 0; k < c; k++)
        {
            if (steps == arlen * arlen)
                break;
            cout << " : " << ar[i][j + step];
            j += step;
            steps++;
        }
        step = - step;
        c++;
    }
}
