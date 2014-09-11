#include <iostream>
#include "mymultisettest.h"

using namespace std;

int main()
{
    MyMultiSetTest mymultisettest;
    QTest::qExec(&mymultisettest);

    return 0;
}

