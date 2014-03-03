#ifndef DISPFILE_H
#define DISPFILE_H

#include "displayer.h"
#include "dispstream.h"

class DispFile : public Displayer, public DispStream
{
public:
    void display(int** ar, int arlen);
};


#endif // DISPFILE_H
