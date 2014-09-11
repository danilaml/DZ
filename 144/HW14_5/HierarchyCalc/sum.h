#ifndef SUM_H
#define SUM_H

#include "node.h"

class Sum : public Node
{
    /// Node for +
public:
    Sum(Node *l, Node *r);
    ~Sum();
    int compute() const;
    std::string toString() const;

private:
    Node *left;
    Node *right;
};

#endif // SUM_H
