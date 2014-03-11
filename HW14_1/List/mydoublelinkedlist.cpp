#include <mydoublelinkedlist.h>
#include <iostream>


MyDoubleLinkedList::MyDoubleLinkedList() : head(nullptr)
{
}

MyDoubleLinkedList::~MyDoubleLinkedList()
{
    while (head != nullptr)
    {
        ListElement *tmp = head->next;
        delete head;
        head = tmp;
    }
}

bool MyDoubleLinkedList::insert(int el, int pos)
{
    ListElement *tempL = head;
    if (pos == 0)
    {
        ListElement *tmp = new ListElement(el, tempL, nullptr);
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
        ListElement *tmp = new ListElement(el, tempL->next, tempL);
        tempL->next = tmp;
        return true;
    }
}

void MyDoubleLinkedList::printList()
{
    ListElement *tempL = head;
    while(tempL != nullptr)
    {
        std::cout << tempL->value << " ";
        tempL = tempL->next;
    }
    std::cout << std::endl;
}

int MyDoubleLinkedList::length()
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

int MyDoubleLinkedList::getElementAt(int pos)
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

bool MyDoubleLinkedList::deleteElementAt(int pos)
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
        tmp->prev = nullptr;
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
            if(tempL->next->next != nullptr)
                tempL->next->next->prev = tempL;
            delete tmp;
            return true;
        }
        else
            return false;
    }
}
