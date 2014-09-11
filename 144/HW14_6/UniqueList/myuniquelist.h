#ifndef MYUNIQUELIST_H
#define MYUNIQUELIST_H

#include "myoutofrangeexception.h"
#include "myemptylistexception.h"
#include "myduplicateexception.h"
#include "mylinkedlist.h"

/// Class that implements linked list with unique elements
class MyUniqueList : public MyLinkedList
{
public:
    MyUniqueList();
    ~MyUniqueList();
    bool contains(int el) const;
    void insert(int el, int pos) throw (MyOutOfRangeException, MyDuplicateException);
    int getElementAt(int pos) const throw (MyOutOfRangeException, MyEmptyListException);
    void deleteElementAt(int pos) throw (MyOutOfRangeException, MyEmptyListException);
};

#endif // MYUNIQUELIST_H
