#include "myuniquelist.h"
#include <iostream>


MyUniqueList::MyUniqueList() : head(nullptr)
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

void MyUniqueList::insert(int el, int pos) throw (MyException)
{
    if (contains(el))
        throw MyException("The element you tried to insert already exists");
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
        throw MyException("Can't insert because pos > len");
    }
    else
    {
        ListElement *tmp = new ListElement(el, tempL->next);
        tempL->next = tmp;
    }
}

void MyUniqueList::printList() const
{
    ListElement *tempL = head;
    while(tempL != nullptr)
    {
        std::cout << tempL->value << " ";
        tempL = tempL->next;
    }
    std::cout << std::endl;
}

int MyUniqueList::length() const
{
    ListElement *tempL = head;
    int len = 0;
    while(tempL != nullptr)
    {
        len++;
        tempL = tempL->next;
    }
    return len;
}

int MyUniqueList::getElementAt(int pos) const throw (MyException)
{
    ListElement *tempL = head;
    while ((pos > 0) && (tempL != nullptr))
    {
        pos--;
        tempL = tempL->next;
    }
    if (pos > 0)
    {
       throw MyException("Can't get element, pos is to high");
    }
    if (head == nullptr)
    {
       throw MyException("Can't get element, list is empty");
    }
    return tempL->value;
}

void MyUniqueList::deleteElementAt(int pos) throw (MyException)
{
    if (head == nullptr)
    {
        throw MyException("Can't delete, list is empty");
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
        throw MyException("Can't delete, pos is too high");
    else
    {
        if (tempL->next != nullptr)
        {
            ListElement *tmp = tempL->next;
            tempL->next = tempL->next->next;
            delete tmp;
        }
        else
            throw MyException("Can't delete, pos is too high");
    }
}
