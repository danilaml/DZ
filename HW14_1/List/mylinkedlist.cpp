#include <iostream>
#include <mylinkedlist.h>


MyLinkedList::MyLinkedList() : head(nullptr)
{
}

bool MyLinkedList::insert(int el, int pos)
{
    ListElement *nl = head;
    if (pos == 0)
    {
        ListElement *tmp = new ListElement;
        tmp->value = el;
        tmp->next = nl;
        head = tmp;
        return true;
    }
    while ((pos > 1) && (nl != nullptr))
    {
        pos--;
        nl = nl->next;
    }
    if (pos > 1 || nl == nullptr)
        return false;
    else
    {
        ListElement *tmp = new ListElement;
        tmp->value = el;
        tmp->next = nl->next;
        nl->next = tmp;
        return true;
    }
}

void MyLinkedList::printList()
{
    ListElement *nl = head;
    while(nl != nullptr)
    {
        std::cout << nl->value << " ";
        nl = nl->next;
    }
    std::cout << std::endl;
}

int MyLinkedList::length()
{
    ListElement *nl = head;
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
    ListElement *nl = head;
    while ((pos > 0) && (nl != nullptr))
    {
        pos--;
        nl = nl->next;
    }
    if (pos > 0)
    {
       std::cout << "Can't get element, pos is to high";
       exit(0);
    }
    return nl->value;
}

bool MyLinkedList::deleteElementAt(int pos)
{
    if (head == nullptr)
    {
        std::cout << "Cannot delete, list is empty";
        exit(0);
    }
    ListElement *nl = head;
    if (pos == 0)
    {
        ListElement *tmp = head->next;
        delete head;
        head = tmp;
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
            ListElement *tmp = nl->next;
            nl->next = nl->next->next;
            delete tmp;
            return true;
        }
        else
            return false;
    }
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


