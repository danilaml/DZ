#include "myuniquelist.h"
#include <iostream>


MyUniqueList::MyUniqueList() : MyLinkedList()
{
}

MyUniqueList::~MyUniqueList()
{
    while (head != nullptr)
    {
        ListElement *tmp = head->next;
        delete head;
        head = tmp;
    }
}

bool MyUniqueList::contains(int el) const
{
    ListElement *tempL = head;
    while(tempL != nullptr)
    {
        if (tempL->value == el)
            return true;
        tempL = tempL->next;
    }
    return false;
}

void MyUniqueList::insert(int el, int pos) throw (MyOutOfRangeException, MyDuplicateException)
{
    if (contains(el))
        throw MyDuplicateException("The element you tried to insert already exists");
    ListElement *tempL = head;
    if (pos == 0)
    {
        ListElement *tmp = new ListElement(el, tempL);
        head = tmp;
        return;
    }
    while ((pos > 1) && (tempL != nullptr))
    {
        pos--;
        tempL = tempL->next;
    }
    if (pos > 1 || tempL == nullptr)
    {
        throw MyOutOfRangeException("Can't insert because pos > len");
    }
    else
    {
        ListElement *tmp = new ListElement(el, tempL->next);
        tempL->next = tmp;
    }
}

int MyUniqueList::getElementAt(int pos) const throw (MyOutOfRangeException, MyEmptyListException)
{
    ListElement *tempL = head;
    while ((pos > 0) && (tempL != nullptr))
    {
        pos--;
        tempL = tempL->next;
    }
    if (pos > 0)
    {
       throw MyOutOfRangeException("Can't get element, pos is to high");
    }
    if (head == nullptr)
    {
       throw MyEmptyListException("Can't get element, list is empty");
    }
    return tempL->value;
}

void MyUniqueList::deleteElementAt(int pos) throw (MyOutOfRangeException, MyEmptyListException)
{
    if (head == nullptr)
    {
        throw MyEmptyListException("Can't delete, list is empty");
    }
    ListElement *tempL = head;
    if (pos == 0)
    {
        ListElement *tmp = head->next;
        delete head;
        head = tmp;
        return;
    }
    while ((pos > 1) && (tempL != nullptr))
    {
        pos--;
        tempL = tempL->next;
    }
    if (pos > 1)
        throw MyOutOfRangeException("Can't delete, pos is too high");
    else
    {
        if (tempL->next != nullptr)
        {
            ListElement *tmp = tempL->next;
            tempL->next = tempL->next->next;
            delete tmp;
        }
        else
            throw MyOutOfRangeException("Can't delete, pos is too high");
    }
}
