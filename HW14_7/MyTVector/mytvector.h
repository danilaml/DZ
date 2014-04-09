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
    MyTVector()
    {
        vec = vector<double>(dim);
        for (int i = 0; i < dim; i++)
        {
            vec[i] = 0;
        }
    }

    MyTVector(vector<double> const &vect)
    {
        vec = vector<double>(dim);

        for (int i = 0; i < vect.size(); i++)
        {
            vec[i] = vect[i];
        }
        for (int i = vect.size(); i < dim; i++)
        {
            vec[i] = 0;
        }
    }

    MyTVector(MyTVector const &mtv) : vec(mtv.vec)
    {
    }

    /// Checks if vector == 0
    bool isNullVector() const
    {
        for (int i = 0; i < dim; i++)
        {
            if (vec[i] != 0)
                return false;
        }
        return true;
    }

    /// Returns scalar (dot) product of 'this' and given MyTVector
    int scalarProduct(MyTVector const &mtv) const
    {
        double res = 0;
        for (int i = 0; i < dim; i++)
        {
            res += vec[i] * mtv.vec[i];
        }
        return res;
    }

    /// Prints this vector
    void printVector() const
    {
        cout << "( ";
        for (int i = 0; i < dim - 1; i++)
        {
            cout << vec[i] << ", ";
        }
        cout << vec[dim - 1] << " )" << endl;
    }

    /// Returns nth element of vector
    double at(int n) const
    {
        return vec.at(n);
    }

    MyTVector operator+(MyTVector const &rightv)
    {
        vector<double> vect(dim);
        for (int i = 0; i < dim; i++)
        {
            vect[i] = vec[i] + rightv.vec[i];
        }
        return (MyTVector(vect));
    }

    MyTVector operator-(MyTVector const &rightv)
    {
        vector<double> vect(dim);
        for (int i = 0; i < dim; i++)
        {
            vect[i] = vec[i] - rightv.vec[i];
        }
        return (MyTVector(vect));
    }

    bool operator==(MyTVector const &rightv) const
    {
        for (int i = 0; i < dim; i++)
        {
            if (vec[i] != rightv.vec[i])
                return false;
        }
        return true;
    }

private:
    vector<double> vec;

};

#endif // MYTVECTOR_H
