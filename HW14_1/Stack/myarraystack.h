#ifndef MYARRAYSTACK_H
#define MYARRAYSTACK_H

#include <mystack.h>

class MyArrayStack : public MyStack
{
public:
    MyArrayStack();
    MyArrayStack(int sz);
    ~MyArrayStack();
    void push(int el);
    int pop();
    int back();
    int size();
    void clear();
    void printStack();
private:
    const int DEFAULT_MAX_SIZE = 10000;
    int max_size = DEFAULT_MAX_SIZE;
    int* elements;
    int current_size;
};

#endif // MYARRAYSTACK_H
