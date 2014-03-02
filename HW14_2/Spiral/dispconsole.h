#ifndef DISPCONSOLE_H
#define DISPCONSOLE_H

#include "displayer.h"

class DispConsole : public Displayer
{
public:
    void display(int** ar, int arlen);
};

#endif // DISPCONSOLE_H
