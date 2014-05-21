#ifndef REVERSECOMPARATOR_H
#define REVERSECOMPARATOR_H

/// Comparator with "inverted" behavior, requires that T has defined > and < operators
template<typename T>
class ReverseComparator : public AbstractComparator<T>
{
public:
    ~ReverseComparator() {}
    /// Returns 1 if left < right, 0 if == and -1 if >
    int compare(T left, T right) const;
};

template<typename T>
int ReverseComparator<T>::compare(T left, T right) const
{
    if (left < right)
        return 1;
    else if (left == right)
        return 0;
    return -1;
}

#endif // REVERSECOMPARATOR_H
