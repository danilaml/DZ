#include "myhashtable.h"
#include <iostream>

MyHashTable::MyHashTable() : ar(new std::list<QString>[1]), size(1), prime(1013)
{
}

MyHashTable::MyHashTable(int initSize) : ar(new std::list<QString>[initSize]), size(initSize), prime(1013)
{
}

MyHashTable::~MyHashTable()
{
    delete ar;
}

int MyHashTable::hash(QString &str) const
{
    int res = 0;
    for (int i = 0; i < str.length(); i++)
    {
        res = (res * prime  + str[i].toLatin1()) % size;
    }

    return res;
}


void MyHashTable::add(QString &str)
{
    if(contains(str)) return;
    ar[hash(str)].push_back(str);
}

bool MyHashTable::contains(QString &str) const
{
    for (QString &elem : ar[hash(str)])
    {
        if(elem == str)
            return true;
    }
    return false;
}

int MyHashTable::tableSize() const
{
    return size;
}

int MyHashTable::loadFactor() const
{
    double res = 0;
    for(int i = 0; i < size; i++)
    {
        res += ar[i].size();
    }
    return (res / size);
}

int MyHashTable::numberOfConflicts() const
{
    unsigned int res = 0;
    for(int i = 0; i < size; i++)
    {
        if(ar[i].size() > 1)
            res += ar[i].size();
    }
    return res;
}

int MyHashTable::biggestConflitSize() const
{
    unsigned int res = 1;
    for(int i = 0; i < size; i++)
    {
        if(ar[i].size() > res)
            res = ar[i].size();
    }
    return res;
}

void MyHashTable::changeHashFunc(int newConst, int newSize)
{
    prime = newConst;
    int sizetmp = size;
    size = newSize;
    std::list<QString> *tmp = new std::list<QString>[newSize];
    for(int i = 0; i < sizetmp; i++)
    {
        while(!ar[i].empty())
        {
            tmp[hash(ar[i].front())].push_back(ar[i].front());
            ar[i].pop_front();
        }
    }
    delete tmp;
}

void MyHashTable::print() const
{
    for(int i = 0; i < size; i++)
    {
        if(!ar[i].empty())
        {
            for(QString &str : ar[i])
            {
                std::cout << "( " << str.toStdString() << " , " << i << " ) ";
            }
            std::cout << std::endl;
        }
    }
}
