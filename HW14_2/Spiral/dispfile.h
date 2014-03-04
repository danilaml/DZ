#ifndef DISPFILE_H
#define DISPFILE_H

#include "displayer.h"
#include "dispstream.h"

class DispFile : public Displayer, public DispStream
{
public:
    /// Class with display method for spiral-like ouput of 2-dimensional array into file "output.out".
    /// It implements Displayer interface and inherits from DispStream
    void display(int** ar, int arlen);
};


#endif // DISPFILE_H
