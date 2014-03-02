#ifndef DISPFILE_H
#define DISPFILE_H

#include "displayer.h"

class DispFile : public Displayer
{
public:
    void display(int** ar, int arlen);
};


#endif // DISPFILE_H
