#ifndef MYDOUBLELINKEDLIST_H
#define MYDOUBLELINKEDLIST_H

#include <mylist.h>

class MyDoubleLinkedList : public MyList {
public:
    MyDoubleLinkedList();
    bool insert(int el, int pos);
    void printList();
    int length();
    int getElementAt(int pos);
    bool deleteElementAt(int pos);
    ~MyDoubleLinkedList();
private:
    struct ListElement
        {
            int value;
            ListElement *next;
            ListElement *prev;
        };
    ListElement *head;
};

#endif // MYDOUBLELINKEDLIST_H
