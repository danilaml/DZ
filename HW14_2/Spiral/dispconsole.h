#ifndef DISPCONSOLE_H
#define DISPCONSOLE_H

#include "displayer.h"
#include "dispstream.h"

class DispConsole : public Displayer, public DispStream
{
public:
    void display(int** ar, int arlen);
};

#endif // DISPCONSOLE_H
