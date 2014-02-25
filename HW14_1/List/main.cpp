#include <iostream>
#include <MyLinkedList.h>

using namespace std;

int main()
{
    using namespace std;

    MyLinkedList *mlst = new MyLinkedList(1,new MyLinkedList(3,nullptr));

    mlst->printList();
    cout << endl << mlst->getElementAt(1) << endl << mlst->length() << endl << endl;

    mlst->insert(2,0);

    mlst->printList();
    cout << endl << mlst->getElementAt(1) << endl << mlst->length() << endl << endl;

    mlst->deleteElementAt(0);

    mlst->printList();
    cout << endl << mlst->getElementAt(1) << endl << mlst->length() << endl << endl;

    //cout << mlst;

    return 0;
}

