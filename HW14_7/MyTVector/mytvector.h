#ifndef MYTVECTOR_H
#define MYTVECTOR_H

#include <vector>
#include <iostream>

using namespace std;

/// @brief Basic vector template
/// @tparam dim dimension of vector
template<typename T, int dim>
class MyTVector
{
public:
    MyTVector() : vec(vector<T>(dim, 0))
    {
    }

    MyTVector(vector<T> const &vect) : vec(vect)
    {
        vec.resize(dim);
    }

    MyTVector(MyTVector const &mtv) : vec(mtv.vec)
    {
    }

    bool isNullVector() const;
    int scalarProduct(MyTVector const &mtv) const;
    void printVector() const;
    T at(int n) const;
    MyTVector operator+(MyTVector const &rightv);
    MyTVector operator-(MyTVector const &rightv);
    bool operator==(MyTVector const &rightv) const;

private:
    vector<T> vec;

};

/// Checks if vector == 0
template<typename T, int dim>
bool MyTVector<T, dim>::isNullVector() const
{
    for (int i = 0; i < dim; i++)
    {
        if (vec[i] != 0)
            return false;
    }
    return true;
}

/// Returns scalar (dot) product of 'this' and given MyTVector
template<typename T, int dim>
int MyTVector<T, dim>::scalarProduct(MyTVector const &mtv) const
{
    T res = 0;
    for (int i = 0; i < dim; i++)
    {
        res += vec[i] * mtv.vec[i];
    }
    return res;
}

/// Prints this vector
template<typename T, int dim>
void MyTVector<T, dim>::printVector() const
{
    cout << "( ";
    for (int i = 0; i < dim - 1; i++)
    {
        cout << vec[i] << ", ";
    }
    cout << vec[dim - 1] << " )" << endl;
}

/// Returns nth element of vector
template<typename T, int dim>
T MyTVector<T, dim>::at(int n) const
{
    return vec.at(n);
}

template<typename T, int dim>
MyTVector<T, dim> MyTVector<T, dim>::operator+(MyTVector const &rightv)
{
    vector<T> vect(dim);
    for (int i = 0; i < dim; i++)
    {
        vect[i] = vec[i] + rightv.vec[i];
    }
    return (MyTVector(vect));
}

template<typename T, int dim>
MyTVector<T, dim> MyTVector<T, dim>::operator-(MyTVector const &rightv)
{
    vector<T> vect(dim);
    for (int i = 0; i < dim; i++)
    {
        vect[i] = vec[i] - rightv.vec[i];
    }
    return (MyTVector(vect));
}

template<typename T, int dim>
bool MyTVector<T, dim>::operator==(MyTVector const &rightv) const
{
    for (int i = 0; i < dim; i++)
    {
        if (vec[i] != rightv.vec[i])
            return false;
    }
    return true;
}

#endif // MYTVECTOR_H
