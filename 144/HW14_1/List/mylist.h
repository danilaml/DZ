#ifndef MYLIST_H
#define MYLIST_H

class MyList {
public:
    virtual ~MyList() {}
    virtual bool insert(int el, int pos) = 0;
    virtual void printList() = 0;
    virtual int length() = 0;
    virtual int getElementAt(int n) = 0;
    virtual bool deleteElementAt(int n) = 0;
};

#endif // MYLIST_H
