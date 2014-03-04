#ifndef MYDOUBLELINKEDLIST_H
#define MYDOUBLELINKEDLIST_H

#include <mylist.h>

class MyDoubleLinkedList : public MyList {
public:
    MyDoubleLinkedList();
    ~MyDoubleLinkedList();
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
            ListElement *prev;

            ListElement(int val, ListElement *nxt, ListElement *prv) : value(val), next(nxt), prev(prv)
            {
            }
        };
    ListElement *head;
};

#endif // MYDOUBLELINKEDLIST_H
