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

bool MyLinkedList::insert(int el, int pos)
{
    ListElement *tempL = head;
    if (pos == 0)
    {
        ListElement *tmp = new ListElement(el, tempL);
        head = tmp;
        return true;
    }
    while ((pos > 1) && (tempL != nullptr))
    {
        pos--;
        tempL = tempL->next;
    }
    if (pos > 1 || tempL == nullptr)
        return false;
    else
    {
        ListElement *tmp = new ListElement(el, tempL->next);
        tempL->next = tmp;
        return true;
    }
}

void MyLinkedList::printList()
{
    ListElement *tempL = head;
    while(tempL != nullptr)
    {
        std::cout << tempL->value << " ";
        tempL = tempL->next;
    }
    std::cout << std::endl;
}

int MyLinkedList::length()
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

int MyLinkedList::getElementAt(int pos)
{
    ListElement *tempL = head;
    while ((pos > 0) && (tempL != nullptr))
    {
        pos--;
        tempL = tempL->next;
    }
    if (pos > 0)
    {
       std::cout << "Can't get element, pos is to high";
    }
    return tempL->value;
}

bool MyLinkedList::deleteElementAt(int pos)
{
    if (head == nullptr)
    {
        std::cout << "Cannot delete, list is empty";
        return false;
    }
    ListElement *tempL = head;
    if (pos == 0)
    {
        ListElement *tmp = head->next;
        delete head;
        head = tmp;
        return true;
    }
    while ((pos > 1) && (tempL != nullptr))
    {
        pos--;
        tempL = tempL->next;
    }
    if (pos > 1)
        return false;
    else
    {
        if (tempL->next != nullptr)
        {
            ListElement *tmp = tempL->next;
            tempL->next = tempL->next->next;
            delete tmp;
            return true;
        }
        else
            return false;
    }
}
