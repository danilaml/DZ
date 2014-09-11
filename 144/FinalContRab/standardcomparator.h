#ifndef STANDARDCOMPARATOR_H
#define STANDARDCOMPARATOR_H

#include "abstractcomparator.h"

/// Comparator with "standard" behavior, requires that T has defined > and < operators
template<typename T>
class StandardComparator : public AbstractComparator<T>
{
public:
    ~StandardComparator() {}
    /// Returns 1 if left > right, 0 if == and -1 if <
    int compare(T left, T right) const;
};

template<typename T>
int StandardComparator<T>::compare(T left, T right) const
{
    if (left > right)
        return 1;
    else if (left == right)
        return 0;
    return -1;
}

#endif // STANDARDCOMPARATOR_H
