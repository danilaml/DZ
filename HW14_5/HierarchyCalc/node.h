#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
    /// Interface for node in parsing tree
public:
    virtual ~Node() {}
    /// Computes node's value
    virtual int compute() const = 0;
    /// Converts node into representable string
    virtual std::string toString() const = 0;
};

#endif // NODE_H
