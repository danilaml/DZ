#include <iostream>
#include <mylinkedlist.h>
#include "listtest.h"

using namespace std;

int main()
{
    using namespace std;

    ListTest lsttest;
    QTest::qExec(&lsttest);

    cout << endl;

    MyLinkedList *mlst = new MyLinkedList();

    mlst->insert(3,0);
    mlst->insert(1,0);

    mlst->printList();
    cout << endl << mlst->getElementAt(1) << endl << mlst->length() << endl << endl;

    mlst->insert(2,1);

    mlst->printList();
    cout << endl << mlst->getElementAt(1) << endl << mlst->length() << endl << endl;

    mlst->deleteElementAt(0);

    mlst->printList();
    cout << endl << mlst->getElementAt(1) << endl << mlst->length() << endl << endl;

    delete mlst;

    return 0;
}

