#ifndef DISPSTREAM_H
#define DISPSTREAM_H

#include <iostream>
#include <fstream>

class DispStream
{
public:
    ///Class with displayStream method for spiral-like ouput of 2-dimensional array into given stream
    void displayStream(int** ar, int arlen, std::ostream& outs);
};

#endif // DISPSTREAM_H
