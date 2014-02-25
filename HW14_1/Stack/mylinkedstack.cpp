#include "mylinkedstack.h"

MyLinkedList::MyLinkedList()
{
    elements = new int[DEFAULT_MAX_SIZE];
    current_size = 0;
}

MyLinkedList::~MyLinkedList()
{
    delete elements;
}

MyLinkedList::MyLinkedList(int sz)
{
    max_size = sz;
    elements = new int[sz];
    current_size = 0;
}

void MyLinkedList::push(int el)
{
    if (current_size == max_size)
    {
        std::cout << "Error: Stack is full!" << std::endl;
        exit(0);
    }
    else
    {
        elements[current_size] = el;
        current_size++;
    }
}

int MyLinkedList::pop()
{
    if (current_size == 0)
    {
        std::cout << "Error: Stack is empty!" << std::endl;
        exit(0);
    }
    else
    {
        current_size--;
        return elements[current_size-1];
    }
}

int MyLinkedList::back()
{
    if (current_size == 0)
    {
        std::cout << "Error: Stack is empty!" << std::endl;
        exit(0);
    }
    else
    {
        return elements[current_size-1];
    }
}

int MyLinkedList::size()
{
    return current_size;
}

void MyLinkedList::clear()
{
    current_size = 0;
}

void MyLinkedList::printStack()
{
    for (int i = 0; i < current_size; i++)
    {
       std::cout << elements[i] << " | ";
    }
    std::cout << std::endl;
}
