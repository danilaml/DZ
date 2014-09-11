#include "dispfile.h"
#include <iostream>
#include <fstream>

using namespace std;

void DispFile::display(int** ar, int arlen)
{
    ofstream out;
    out.open("output.out");

    displayStream(ar, arlen, out);

    out.close();
}
