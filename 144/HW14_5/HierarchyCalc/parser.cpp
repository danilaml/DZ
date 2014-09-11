#include "parser.h"
#include "num.h"
#include "mult.h"
#include "div.h"
#include "sum.h"
#include "sub.h"

Parser::Parser() : pos(0)
{
}

Node* Parser::parse(std::string expr)
{
    while (expr[pos] == ' ' || expr[pos] == '(' || expr[pos] == ')')
    {
        pos++;
    }

    if ((expr[pos] >= '0') && (expr[pos] <= '9'))
    {
        int num = 0;
        while ((pos < expr.length()) && (expr[pos] >= '0') && (expr[pos] <= '9'))
        {
            num = (num * 10) + (expr[pos] - '0');
            pos++;
        }
        return (new Num(num));
    }

    Node *left;
    Node *right;
    if (expr[pos] == '+')
    {
        pos++;
        left = parse(expr);
        right = parse(expr);
        return (new Sum(left, right));
    }
    if (expr[pos] == '-')
    {
        pos++;
        left = parse(expr);
        right = parse(expr);
        return (new Sub(left, right));
    }
    if (expr[pos] == '*')
    {
        pos++;
        left = parse(expr);
        right = parse(expr);
        return (new Mult(left, right));
    }
    if (expr[pos] == '/')
    {
        pos++;
        left = parse(expr);
        right = parse(expr);
        return (new Div(left, right));
    }

    return (new Num(INT_MIN)); // shouldn't be reached if input is correct
}
