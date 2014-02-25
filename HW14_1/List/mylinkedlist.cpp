#include <iostream>
#include <mylinkedlist.h>


MyLinkedList::MyLinkedList(int el, MyLinkedList *nx)
{
    head = el;
    next = nx;
}

bool MyLinkedList::insert(int el, int pos)
{
    MyLinkedList *nl = next;
    while ((pos > 0) && (nl != nullptr))
    {
        pos--;
        nl = nl->next;
    }
    if (pos > 0)
        return false;
    else
    {
        nl->next = new MyLinkedList(nl->head, nl->next);
        nl->head = el;
        return true;
    }
}

void MyLinkedList::printList()
{
    MyLinkedList *nl = this;
    while(nl != nullptr)
    {
        std::cout << nl->head << " ";
        nl = nl->next;
    }
    std::cout << std::endl;
}

int MyLinkedList::length()
{
    MyLinkedList *nl = this;
    int len = 0;
    while(nl != nullptr)
    {
        len++;
        nl = nl->next;
    }
    return len;
}

int MyLinkedList::getElementAt(int pos)
{
    MyLinkedList *nl = this;
    while ((pos > 0) && (nl != nullptr))
    {
        pos--;
        nl = nl->next;
    }
    //if (pos > 0) {}
    return nl->head;
}

bool MyLinkedList::deleteElementAt(int pos)
{
    MyLinkedList *nl = this;
    if (pos == 0)
    {
        *nl = *this->next;
        return true;
    }
    while ((pos > 1) && (nl != nullptr))
    {
        pos--;
        nl = nl->next;
    }
    if (pos > 1)
        return false;
    else
    {
        if (nl->next != nullptr)
        {
            MyLinkedList *temp = nl->next;
            nl->next = nl->next->next;
            temp->next = nullptr;
            delete temp;
            return true;
        }
        else
            return false;
    }
}

MyLinkedList::~MyLinkedList()
{
    delete next;
}


