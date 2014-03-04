#include "dispstream.h"

using namespace std;

void DispStream::displayStream(int** ar, int arlen, ostream& outs)
{
    int i = (arlen / 2) + (arlen % 2) - 1;
    int j = i;
    int step = 1;
    int steps = 1;
    int c = 1;
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
