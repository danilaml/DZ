#include <mydoublelinkedlist.h>
#include <iostream>


MyDoubleLinkedList::MyDoubleLinkedList() : head(nullptr)
{
}

bool MyDoubleLinkedList::insert(int el, int pos)
{
    ListElement *nl = head;
    if (pos == 0)
    {
        ListElement *tmp = new ListElement;
        tmp->value = el;
        tmp->next = nl;
        tmp->prev = nullptr;
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
        tmp->prev = nl;
        nl->next = tmp;
        return true;
    }
}

void MyDoubleLinkedList::printList()
{
    ListElement *nl = head;
    while(nl != nullptr)
    {
        std::cout << nl->value << " ";
        nl = nl->next;
    }
    std::cout << std::endl;
}

int MyDoubleLinkedList::length()
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

int MyDoubleLinkedList::getElementAt(int pos)
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

bool MyDoubleLinkedList::deleteElementAt(int pos)
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
        tmp->prev = nullptr;
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
            if(nl->next->next != nullptr)
                nl->next->next->prev = nl;
            delete tmp;
            return true;
        }
        else
            return false;
    }
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

