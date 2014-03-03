#include "dispstream.h"

using namespace std;

void DispStream::displayStream(int** ar, int arlen, ostream& outs)
{
    int i, j, step, steps, c;
    i = j = (arlen / 2) + (arlen % 2) - 1;
    step = 1;
    steps = 1;
    c = 1;
    outs << ar[i][j];

    while (steps < arlen * arlen)
    {
        for (int k = 0; k < c; k++)
        {
            if (steps == arlen * arlen)
                break;
            outs << " : " << ar[i + step][j];
            i += step;
            steps++;
        }
        for (int k = 0; k < c; k++)
        {
            if (steps == arlen * arlen)
                break;
            outs << " : " << ar[i][j + step];
            j += step;
            steps++;
        }
        step = - step;
        c++;
    }
}
