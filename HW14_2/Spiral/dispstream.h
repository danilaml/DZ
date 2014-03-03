#ifndef DISPSTREAM_H
#define DISPSTREAM_H

#include <iostream>
#include <fstream>

class DispStream
{
public:
    void displayStream(int** ar, int arlen, std::ostream& outs);
};

#endif // DISPSTREAM_H
