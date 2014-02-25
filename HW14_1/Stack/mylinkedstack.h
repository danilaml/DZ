#ifndef MYLINKEDSTACK_H
#define MYLINKEDSTACK_H

#include <mystack.h>

class MyLinkedStack : public MyStack
{
public:
    MyLinkedStack();
    ~MyLinkedStack();
    void push(int el);
    int pop();
    int back();
    int size();
    void clear();
    void printStack();
private:
    MyLinkedStack* next;
    int head;
    int current_size;
};

#endif // MYLINKEDSTACK_H
