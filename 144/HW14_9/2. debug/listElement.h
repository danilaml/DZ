#pragma once

#include <iostream>


template <typename Type> class ListElement
{
public:
    ListElement(): value(0), next(NULL), prev(NULL) {}
    ListElement(Type val): value(val), next(NULL), prev(NULL) {}
    ListElement(Type val, ListElement<Type>* nextElem): next(nextElem), prev(NULL) {}
    ListElement(Type val, ListElement<Type>* nextElem, ListElement<Type>* prevElem):
        next(nextElem), prev(prevElem) {}
    void setValue(Type val)
    {
        value = val;
    }
    Type getValue()
    {
        return value;
    }
    void setNext(ListElement<Type>* nextElem)
    {
        next = nextElem;	
    }
    ListElement<Type>* getNext()
    {
        return next;
    }
    void setPrev(ListElement<Type>* prevElem)
    {
        prev = prevElem;
    }
    ListElement<Type>* getPrev()
    {
        return prev;
    }
    ~ListElement()
    {
        if (next != NULL)
            delete next;
    }
private:
    Type value;
    ListElement<Type>* next;
    ListElement<Type>* prev;
};

