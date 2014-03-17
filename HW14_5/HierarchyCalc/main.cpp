#include <iostream>
#include "parser.h"

using namespace std;

int main()
{
    Parser *prs = new Parser();
    Node *result = prs->parse(std::string("(* (+ 1 1) 2)"));

    cout << result->toString() << endl;
    cout << result->compute() << endl;

    delete result;
    delete prs;

    return 0;
}

