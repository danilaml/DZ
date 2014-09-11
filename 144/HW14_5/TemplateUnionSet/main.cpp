#include <iostream>
#include "myset.h"
#include "intsettests.h"

using namespace std;

int main()
{
    IntSetTests intsettests;
    QTest::qExec(&intsettests);

    MySet<int> msfst;
    msfst.add(1);
    msfst.add(2);
    msfst.add(3);
    msfst.print();

    MySet<int> mssnd;
    mssnd.add(2);
    mssnd.add(3);
    mssnd.add(4);
    mssnd.print();

    MySet<int> un = msfst.unite(mssnd);
    un.print();

    MySet<int> intrsct = msfst.intersect(mssnd);
    intrsct.print();

    return 0;
}

