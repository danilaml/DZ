#ifndef MYMULTISET_H
#define MYMULTISET_H

#include <map>
#include <iostream>

using namespace std;

/// Template class that acts as MultiSet and implements basic operations
template<typename T>
class MyMultiSet
{
public:
    MyMultiSet() {}

    void add(T elem);
    void del(T elem);
    int size() const;
    bool contains(T elem) const;
    void print() const;

private:
    map<T, int> mp;
};

/// Adds given element
template<typename T>
void MyMultiSet<T>::add(T elem)
{
    if (!this->contains(elem))
        mp.insert(pair<T, int>(elem, 1));
    else
        mp.at(elem)++;
}

/// Deletes given element
template<typename T>
void MyMultiSet<T>::del(T elem)
{
    if (mp.empty())
        cout << "Union is empty" <<endl;
    else
    {
        typename map<T, int>::iterator it = mp.find(elem);
        if (it != mp.end())
        {
            it->second--;
            if (it->second == 0)
                mp.erase(it);
        }
    }
}

/// Returns number of elements
template<typename T>
int MyMultiSet<T>::size() const
{
    int res = 0;
    for (pair<T, int> const &el : mp)
    {
        res += el.second;
    }
    return res;
}

/// Checks if MultiSet contains given element
template<typename T>
bool MyMultiSet<T>::contains(T elem) const
{
    return (mp.find(elem) != mp.end());
}

/// Prints MultiSet
template<typename T>
void MyMultiSet<T>::print() const
{
    for (pair<T, int> const &el : mp)
    {
        cout << el.first << ", count: " << el.second << " ";
    }
    cout << endl;
}

#endif // MYMULTISET_H
