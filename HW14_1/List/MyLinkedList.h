#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <mylist.h>

class MyLinkedList : public MyList {
public:
    //MyLinkedList();
    MyLinkedList(int, MyLinkedList*);
    bool insert(int el, int pos);
    void printList();
    int length();
    int getElementAt(int pos);
    bool deleteElementAt(int pos);
    ~MyLinkedList();
private:
    //int head;
    MyLinkedList *next;
};

#endif // MYLINKEDLIST_H
