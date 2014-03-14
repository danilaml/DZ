#include "myhashtable.h"
#include <iostream>

MyHashTable::MyHashTable() : hsf(new HashFunction(1013)), ar(new QStringList[1]), size(1)
{
}

MyHashTable::MyHashTable(int initSize) : hsf(new HashFunction(1013)), ar(new QStringList[initSize]), size(initSize)
{
}

MyHashTable::MyHashTable(int initSize, HashFunction *inithsf) : hsf(inithsf), ar(new QStringList[initSize]), size(initSize)
{
}

MyHashTable::~MyHashTable()
{
    delete[] ar;
}

void MyHashTable::add(QString &str)
{
    if(contains(str)) return;
    ar[hsf->hash(str, size)].push_back(str);
}

bool MyHashTable::contains(QString &str) const
{
    return ar[hsf->hash(str, size)].contains(str);
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
    int res = 0;
    for(int i = 0; i < size; i++)
    {
        if(ar[i].size() > 1)
            res += ar[i].size();
    }
    return res;
}

int MyHashTable::biggestConflitSize() const
{
    int res = 1;
    for(int i = 0; i < size; i++)
    {
        if(ar[i].size() > res)
            res = ar[i].size();
    }
    return res;
}

void MyHashTable::changeHashFunc(HashFunction *newhsf)
{
    delete hsf;
    hsf = newhsf;
    QStringList *tmp = new QStringList[size];
    for(int i = 0; i < size; i++)
    {
        while(!ar[i].isEmpty())
        {
            tmp[hsf->hash(ar[i].front(), size)].push_back(ar[i].front());
            ar[i].pop_front();
        }
    }
    delete[] ar;
    ar = tmp;
}

void MyHashTable::changeHashSize(int newSize)
{
    int sizetmp = size;
    size = newSize;
    QStringList *tmp = new QStringList[newSize];
    for(int i = 0; i < sizetmp; i++)
    {
        while(!ar[i].isEmpty())
        {
            tmp[hsf->hash(ar[i].front(), size)].push_back(ar[i].front());
            ar[i].pop_front();
        }
    }
    delete[] ar;
    ar = tmp;
}

void MyHashTable::print() const
{
    for(int i = 0; i < size; i++)
    {
        if(!ar[i].isEmpty())
        {
            for(QString &str : ar[i])
            {
                std::cout << "( " << str.toStdString() << " , " << i << " ) ";
            }
            std::cout << std::endl;
        }
    }
}
