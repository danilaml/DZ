#include <mydoublelinkedlist.h>
#include <iostream>


MyDoubleLinkedList::MyDoubleLinkedList(int el, MyDoubleLinkedList *nx, MyDoubleLinkedList *pv)
{
    head = el;
    next = nx;
    prev = pv;
}

bool MyDoubleLinkedList::insert(int el, int pos)
{
    MyDoubleLinkedList *nl = next;
    while ((pos > 0) && (nl != nullptr))
    {
        pos--;
        nl = nl->next;
    }
    if (pos > 0)
        return false;
    else
    {
        nl->next = new MyDoubleLinkedList(nl->head, nl->next, nl);
        nl->head = el;
        return true;
    }
}

void MyDoubleLinkedList::printList()
{
    MyDoubleLinkedList *nl = this;
    while(nl != nullptr)
    {
        std::cout << nl->head << " ";
        nl = nl->next;
    }
    std::cout << std::endl;
}

int MyDoubleLinkedList::length()
{
    MyDoubleLinkedList *nl = this;
    int len = 0;
    while(nl != nullptr)
    {
        len++;
        nl = nl->next;
    }
    return len;
}

int MyDoubleLinkedList::getElementAt(int pos)
{
    MyDoubleLinkedList *nl = next;
    while ((pos > 0) && (nl != nullptr))
    {
        pos--;
        nl = nl->next;
    }
    //if (pos > 0) {}
    return head;
}

bool MyDoubleLinkedList::deleteElementAt(int pos)
{
    MyDoubleLinkedList *nl = this;
    if (pos == 0)
    {
        *nl = *this->next;
        nl->prev = nullptr;
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
            MyDoubleLinkedList *temp = nl->next;
            nl->next = nl->next->next;
            nl->next->prev = nl->prev;
            temp->next = nullptr;
            delete temp;
            return true;
        }
        else
            return false;
    }
}

MyDoubleLinkedList::~MyDoubleLinkedList()
{
    delete next;
}

