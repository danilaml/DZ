#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <mylist.h>

class MyLinkedList : public MyList {
public:
    MyLinkedList();
    ~MyLinkedList();
    bool insert(int el, int pos);
    void printList();
    int length();
    int getElementAt(int pos);
    bool deleteElementAt(int pos);

private:
    struct ListElement
        {
            int value;
            ListElement *next;

            ListElement(int val, ListElement *nxt) : value(val), next(nxt)
            {
            }
        };
    ListElement *head;
};

#endif // MYLINKEDLIST_H
