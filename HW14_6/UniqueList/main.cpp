#include <iostream>
#include "uniquelisttest.h"

using namespace std;

int main()
{
    UniqueListTest ulsttest;
    QTest::qExec(&ulsttest);

    return 0;
}

