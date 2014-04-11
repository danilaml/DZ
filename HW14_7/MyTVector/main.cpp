#include <iostream>
#include "mytvectortest.h"

using namespace std;

int main()
{
    MyTVectorTest mtvtest;
    QTest::qExec(&mtvtest);

    return 0;
}
