#ifndef DISPLAYER_H
#define DISPLAYER_H

class Displayer
{
public:
    ///Interface that describes display method for displaying 2-dimensional array
    virtual void display(int** ar, int arlen) = 0;
};

#endif // DISPLAYER_H
