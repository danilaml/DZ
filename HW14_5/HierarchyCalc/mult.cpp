#include "mult.h"

Mult::Mult(Node *l, Node *r) : left(l), right(r)
{
}

Mult::~Mult()
{
    delete left;
    delete right;
}

int Mult::compute() const
{
    return (left->compute() * right->compute());
}

std::string Mult::toString() const
{
    return std::string("( * " + left->toString() + " " + right->toString() + " )");
}
