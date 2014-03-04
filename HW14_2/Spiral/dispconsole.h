#ifndef DISPCONSOLE_H
#define DISPCONSOLE_H

#include "displayer.h"
#include "dispstream.h"

class DispConsole : public Displayer, public DispStream
{
public:
    /// Class with display method for spiral-like ouput of 2-dimensional array into console.
    /// It implements Displayer interface and inherits from DispStream
    void display(int** ar, int arlen);
};

#endif // DISPCONSOLE_H
