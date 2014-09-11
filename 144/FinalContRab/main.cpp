#include <iostream>
#include "comparatortest.h"

int main()
{
    ComparatorTest cmpTest;
    QTest::qExec(&cmpTest);

    return 0;
}

