#ifndef MYLIST_H
#define MYLIST_H

/// Interface for generic list
class MyList {
public:
    virtual ~MyList() {}
    virtual void insert(int el, int pos) = 0;
    virtual void printList() const = 0;
    virtual int length() const = 0 ;
    virtual int getElementAt(int n) const = 0;
    virtual void deleteElementAt(int n) = 0;
};

#endif // MYLIST_H
