#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <QList>
#include "myemptyexception.h"

/// Template for basic implementation of queue with priorities
template<typename T>
class MyQueue
{
public:
    /// Method that adds element 'val' to the queue with priority = 'priority'.
    void enqueue(T val, int priority)
    {
        for (QueueElement pr : lst)
        {
            int i = 0;
            if (priority < pr.prior)
            {
                lst.insert(i, QueueElement(val, priority));
                return;
            }
            i++;
        }
        lst.push_front(QueueElement(val, priority));
        return;
    }

    /// Method that gets element with highest priority and deletes it from the queue.
    T dequeue() throw(MyEmptyException)
    {
        if (lst.size() == 0)
            throw (MyEmptyException());
        T tmp = lst.back().val;
        lst.pop_back();
        return tmp;
    }

    /// Checks if element 'val' is already in queue
    bool contains(int val)
    {
        for (QueueElement el : lst)
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

    QList<QueueElement> lst;
};

#endif // MYQUEUE_H
