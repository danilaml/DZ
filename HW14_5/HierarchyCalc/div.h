#ifndef DIV_H
#define DIV_H

#include "node.h"

class Div : public Node
{
    /// Node for /
public:
    Div(Node *l, Node *r);
    ~Div();
    int compute() const;
    std::string toString() const;

private:
    Node *left;
    Node *right;
};

#endif // DIV_H
