#ifndef MYUNIQUELIST_H
#define MYUNIQUELIST_H

#include "myexception.h"

class MyUniqueList
{
    /// Class that implements linked list with unique elements
public:
    MyUniqueList();
    ~MyUniqueList();
    bool contains(int el) const;
    void insert(int el, int pos) throw (MyException);
    void printList() const;
    int length() const;
    int getElementAt(int pos) const throw (MyException);
    void deleteElementAt(int pos) throw (MyException);

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

#endif // MYUNIQUELIST_H
