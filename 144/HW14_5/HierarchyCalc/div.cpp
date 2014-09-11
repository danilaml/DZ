#include "div.h"

Div::Div(Node *l, Node *r) : left(l), right(r)
{
}

Div::~Div()
{
    delete left;
    delete right;
}

int Div::compute() const
{
    return (left->compute() / right->compute());
}

std::string Div::toString() const
{
    return std::string("( / " + left->toString() + " " + right->toString() + " )");
}
