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
    bool isEmpty();
    void clear();
    void printStack();

private:
    struct StackElement
        {
            int value;
            StackElement *next;

            StackElement(int val, StackElement *nxt) : value(val), next(nxt)
            {
            }
        };
    StackElement *head;
};

#endif // MYLINKEDSTACK_H
