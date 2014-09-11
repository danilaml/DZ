#include <iostream>
#include <mylinkedlist.h>


MyLinkedList::MyLinkedList() : head(nullptr)
{
}

MyLinkedList::~MyLinkedList()
{
    while (head != nullptr)
    {
        ListElement *tmp = head->next;
        delete head;
        head = tmp;
    }
}

void MyLinkedList::insert(int el, int pos)
{
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
        return;
    else
    {
        ListElement *tmp = new ListElement(el, tempL->next);
        tempL->next = tmp;
        return;
    }
}

void MyLinkedList::printList() const
{
    ListElement *tempL = head;
    while(tempL != nullptr)
    {
        std::cout << tempL->value << " ";
        tempL = tempL->next;
    }
    std::cout << std::endl;
}

int MyLinkedList::length() const
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

int MyLinkedList::getElementAt(int pos) const
{
    ListElement *tempL = head;
    while ((pos > 0) && (tempL != nullptr))
    {
        pos--;
        tempL = tempL->next;
    }
    if (pos > 0)
    {
       std::cout << "Can't get element, pos is to high" << std::endl;
       return INT_MIN;
    }
    if (head == nullptr)
    {
       std::cout << "Can't get element, list is empty" << std::endl;
       return INT_MIN;
    }
    return tempL->value;
}

void MyLinkedList::deleteElementAt(int pos)
{
    if (head == nullptr)
    {
        std::cout << "Cannot delete, list is empty" << std::endl;
        return;
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
        return;
    else
    {
        if (tempL->next != nullptr)
        {
            ListElement *tmp = tempL->next;
            tempL->next = tempL->next->next;
            delete tmp;
            return;
        }
        else
            return;
    }
}
