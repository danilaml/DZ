#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <mylist.h>

/// Class that implements linked list with unique elements
class MyLinkedList : public MyList {
public:
    MyLinkedList();
    ~MyLinkedList();
    void insert(int el, int pos);
    void printList() const;
    int length() const;
    int getElementAt(int pos) const;
    void deleteElementAt(int pos);

protected:
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
