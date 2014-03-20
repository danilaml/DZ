#include <iostream>
#include "parser.h"
#include "hierarchycalctest.h"

using namespace std;

int main()
{
    HierarchyCalcTest hcttest;
    QTest::qExec(&hcttest);

    Parser *prs = new Parser();
    Node *result = prs->parse(std::string("(* (+ 1 1) 2)"));

    cout << result->toString() << endl;
    cout << result->compute() << endl;

    delete result;
    delete prs;

    return 0;
}

