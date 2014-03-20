#ifndef MYUNIONSET_H
#define MYUNIONSET_H

#include <list>
#include <iostream>

template<typename T>
class MySet
{
    /// Template class that acts as Set and implements basic operations
public:
    MySet() {}

    void add(T elem)
    {
        if (!this->contains(elem))
            lst.push_back(elem);
    }

    void del(T elem)
    {
        if (lst.empty())
            std::cout << "Union is empty" <<std::endl;
        else
            lst.remove(elem);
    }

    bool contains(T elem) const
    {
        for (const T &el : lst)
        {
            if (el == elem)
                return true;
        }
        return false;
    }

    MySet<T> intersect(MySet<T> ms) const
    {
        MySet<T> res;
        for (const T &el : lst)
        {
            if (ms.contains(el))
                res.add(el);
        }
        return res;
    }

    MySet<T> unite(MySet<T> ms) const
    {
        MySet<T> res = ms;
        for (const T &el : lst)
        {
                res.add(el);
        }
        return res;
    }

    void print() const
    {
        for (const T &el : lst)
        {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }

private:
    std::list<T> lst;
};

#endif // MYUNIONSET_H
