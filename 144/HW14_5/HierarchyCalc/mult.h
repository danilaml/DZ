#ifndef MULT_H
#define MULT_H

#include "node.h"

class Mult : public Node
{
    /// Node for *
public:
    Mult(Node *l, Node *r);
    ~Mult();
    int compute() const;
    std::string toString() const;

private:
    Node *left;
    Node *right;
};

#endif // MULT_H
