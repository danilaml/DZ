#ifndef PARSER_H
#define PARSER_H

#include "node.h"

class Parser
{
    /// Class for parsing string into tree
public:
    Parser();
    Node* parse(std::string expr);

private:
    unsigned int pos;
};

#endif // PARSER_H
