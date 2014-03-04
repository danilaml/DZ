#include "mylinkedstack.h"
#include <iostream>

MyLinkedStack::MyLinkedStack() : head(nullptr)
{
}

MyLinkedStack::~MyLinkedStack()
{
    while (head != nullptr)
    {
        StackElement *tmp = head->next;
        delete head;
        head = tmp;
    }
}

void MyLinkedStack::push(int el)
{
    StackElement *tmp = new StackElement(el, head);
    head = tmp;
}

int MyLinkedStack::pop()
{
    if (!isEmpty())
    {
        StackElement *tmp = head;
        head = head->next;
        int res = tmp->value;
        delete tmp;
        return res;
    }
    else
    {
        std::cout << "Cannot pop, stack is empty";
    }
}

int MyLinkedStack::back()
{
    if(head == nullptr)
    {
        std::cout << "Cannot get back, stack is empty";
    }
    return head->value;
}

int MyLinkedStack::size()
{
    StackElement *tmp = head;
    int res = 0;
    while (tmp != nullptr)
    {
        tmp = tmp->next;
        res++;
    }
    return res;
}

void MyLinkedStack::clear()
{
    while (head != nullptr)
    {
        StackElement *tmp = head->next;
        delete head;
        head = tmp;
    }
}

void MyLinkedStack::printStack()
{
    StackElement *nl = head;
    if(head == nullptr)
        std::cout << "[]";
    while(nl != nullptr)
    {
        std::cout << nl->value << " ";
        nl = nl->next;
    }
    std::cout << std::endl;
}

bool MyLinkedStack::isEmpty()
{
    return (head == nullptr);
}


