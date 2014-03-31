#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <list>
#include "myemptyexception.h"

/// Template for basic implementation of queue with priorities
template<typename T>
class MyQueue
{
public:
    void enqueue(T val, int priority)
    {
        for(QueueElement pr : lst)
        {
            if(priority < pr.prior)
            {
                lst.push_front(QueueElement(val, priority));
                return;
            }
        }
        lst.push_front(QueueElement(val, priority));
        return;
    }

    T dequeue() throw(MyEmptyException)
    {
        if(lst.size() == 0)
            throw (new MyEmptyException());
        T tmp = lst.back().val;
        lst.pop_back();
        return tmp;
    }

    bool contains(int val)
    {
        for(QueueElement el : lst)
        {
            if(val == el.val)
                return true;
        }
        return false;
    }

private:
    struct QueueElement
    {
        QueueElement(T v, int p) : val(v), prior(p)
        {
        }

        T val;
        int prior;
    };

    std::list<QueueElement> lst;
};

#endif // MYQUEUE_H
