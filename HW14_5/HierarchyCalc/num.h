#ifndef NUM_H
#define NUM_H

#include "node.h"

class Num : public Node
{
    /// Node for number
public:
    Num(int numb);
    int compute() const;
    std::string toString() const;

private:
    int num;
};

#endif // NUM_H
