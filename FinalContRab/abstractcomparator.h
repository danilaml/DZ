#ifndef ABSTRACTCOMPARATOR_H
#define ABSTRACTCOMPARATOR_H

///Interface for comparator
template<typename T>
class AbstractComparator
{
public:
    virtual ~AbstractComparator() {}
    /// Method that takes to args of type T and returns int (compare them)
    /// For a standard behaviour it is suggested to return 0 if left == right, neagative if left > right and positve otherwise
    virtual int compare(T left, T right) const = 0;
};

#endif // ABSTRACTCOMPARATOR_H
