#ifndef MYTVECTOR_H
#define MYTVECTOR_H

#include <vector>
#include <iostream>

using namespace std;

/// @brief Basic vector template
/// @tparam dim dimension of vector
template<int dim>
class MyTVector
{
public:
    MyTVector() : vec(vector<double>(dim, 0))
    {
    }

    MyTVector(vector<double> const &vect) : vec(vect)
    {
        vec.resize(dim, 0);
    }

    MyTVector(MyTVector const &mtv) : vec(mtv.vec)
    {
    }

    bool isNullVector() const;
    int scalarProduct(MyTVector const &mtv) const;
    void printVector() const;
    double at(int n) const;
    MyTVector operator+(MyTVector const &rightv);
    MyTVector operator-(MyTVector const &rightv);
    bool operator==(MyTVector const &rightv) const;

private:
    vector<double> vec;

};

/// Checks if vector == 0
template<int dim>
bool MyTVector<dim>::isNullVector() const
{
    for (int i = 0; i < dim; i++)
    {
        if (vec[i] != 0)
            return false;
    }
    return true;
}

/// Returns scalar (dot) product of 'this' and given MyTVector
template<int dim>
int MyTVector<dim>::scalarProduct(MyTVector const &mtv) const
{
    double res = 0;
    for (int i = 0; i < dim; i++)
    {
        res += vec[i] * mtv.vec[i];
    }
    return res;
}

/// Prints this vector
template<int dim>
void MyTVector<dim>::printVector() const
{
    cout << "( ";
    for (int i = 0; i < dim - 1; i++)
    {
        cout << vec[i] << ", ";
    }
    cout << vec[dim - 1] << " )" << endl;
}

/// Returns nth element of vector
template<int dim>
double MyTVector<dim>::at(int n) const
{
    return vec.at(n);
}

template<int dim>
MyTVector<dim> MyTVector<dim>::operator+(MyTVector const &rightv)
{
    vector<double> vect(dim);
    for (int i = 0; i < dim; i++)
    {
        vect[i] = vec[i] + rightv.vec[i];
    }
    return (MyTVector(vect));
}

template<int dim>
MyTVector<dim> MyTVector<dim>::operator-(MyTVector const &rightv)
{
    vector<double> vect(dim);
    for (int i = 0; i < dim; i++)
    {
        vect[i] = vec[i] - rightv.vec[i];
    }
    return (MyTVector(vect));
}

template<int dim>
bool MyTVector<dim>::operator==(MyTVector const &rightv) const
{
    for (int i = 0; i < dim; i++)
    {
        if (vec[i] != rightv.vec[i])
            return false;
    }
    return true;
}

#endif // MYTVECTOR_H
