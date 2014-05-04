#pragma once

template <typename Type> class AbstractStack
{
public:
    virtual void push(Type val) = 0;
    virtual Type pop() = 0;
    virtual Type top() = 0;
    virtual bool isEmpty() = 0;
};
