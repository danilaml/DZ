#include "dispconsole.h"
#include <iostream>

using namespace std;

void DispConsole::display(int** ar, int arlen)
{
    displayStream(ar, arlen, cout);
}
