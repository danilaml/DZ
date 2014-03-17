#include "sub.h"

Sub::Sub(Node *l, Node *r) : left(l), right(r)
{
}

Sub::~Sub()
{
    delete left;
    delete right;
}

int Sub::compute() const
{
    return (left->compute() - right->compute());
}

std::string Sub::toString() const
{
    return std::string("( - " + left->toString() + " " + right->toString() + " )");
}
