#ifndef SORTER_H
#define SORTER_H

class Sorter
{
public:
    /// Sorter interface with sort method
    virtual void sort(int ar[], int arlen) = 0;
    virtual ~Sorter() {}
};

#endif // SORTER_H
