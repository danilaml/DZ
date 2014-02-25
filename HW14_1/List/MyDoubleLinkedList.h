#ifndef MYDOUBLELINKEDLIST_H
#define MYDOUBLELINKEDLIST_H

#include <mylist.h>

class MyDoubleLinkedList : public MyList {
public:
    //MyDoubleLinkedList();
    MyDoubleLinkedList(int, MyDoubleLinkedList*,MyDoubleLinkedList*);
    bool insert(int el, int pos);
    void printList();
    int length();
    int getElementAt(int pos);
    bool deleteElementAt(int pos);
    ~MyDoubleLinkedList();
private:
    //int head;
    MyDoubleLinkedList *next;
    MyDoubleLinkedList *prev;
};

#endif // MYDOUBLELINKEDLIST_H
