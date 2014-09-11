#include <iostream>
#include "myshareptrtest.h"

using namespace std;

int main()
{
    MySharePtrTest msptest;
    QTest::qExec(&msptest);

    return 0;
}

