#ifndef MYARRAYSTACK_H
#define MYARRAYSTACK_H

#include <mystack.h>

class MyArrayStack : public MyStack
{
public:
    MyArrayStack();
    MyArrayStack(int initSize);
    ~MyArrayStack();
    void push(int el);
    int pop();
    int back();
    int size();
    bool isEmpty();
    void clear();
    void printStack();

private:
    const int defaultMaxSize = 10000;
    int maxSize = defaultMaxSize;
    int* elements;
    int currentSize;
};

#endif // MYARRAYSTACK_H
