#include <iostream>
#include "myqueuetest.h"

using namespace std;

int main()
{
    MyQueueTest mqtest;
    QTest::qExec(&mqtest);

    return 0;
}

