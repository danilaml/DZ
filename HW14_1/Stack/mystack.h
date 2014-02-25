#ifndef MYSTACK_H
#define MYSTACK_H

class MyStack
{
public:
    virtual void push(int el) = 0;
    virtual int pop() = 0;
    virtual int back() = 0;
    virtual int size() = 0;
    virtual void clear() = 0;
    virtual ~MyStack() {}
};

#endif // MYSTACK_H
