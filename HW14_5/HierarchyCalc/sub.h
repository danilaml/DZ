#ifndef SUB_H
#define SUB_H

#include "node.h"

class Sub : public Node
{
    /// Node for -
public:
    Sub(Node *l, Node *r);
    ~Sub();
    int compute() const;
    std::string toString() const;

private:
    Node *left;
    Node *right;
};

#endif // SUB_H
