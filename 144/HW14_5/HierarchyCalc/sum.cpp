#include "sum.h"

Sum::Sum(Node *l, Node *r) : left(l), right(r)
{
}

Sum::~Sum()
{
    delete left;
    delete right;
}

int Sum::compute() const
{
    return (left->compute() + right->compute());
}

std::string Sum::toString() const
{
    return std::string("( + " + left->toString() + " " + right->toString() + " )");
}
