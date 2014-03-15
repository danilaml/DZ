#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <QObject>
#include <QStringList>
#include "hashfunction.h"

class MyHashTable
{
    /// HashTable class with basic hashtable methods
public:
    MyHashTable();
    MyHashTable(int initSize);
    MyHashTable(int initSize, HashFunction *inithsf);
    ~MyHashTable();
    void add(QString &str);
    void del(QString &str);
    bool contains(QString &str) const;
    int tableSize() const;
    double loadFactor() const;
    int numberOfConflicts() const;
    int biggestConflitSize() const;
    void changeHashFunc(HashFunction *newhsf);
    void changeHashSize(int newSize);
    void print() const;

private:
    HashFunction *hsf;
    QStringList *ar;
    int size;
};

#endif // MYHASHTABLE_H
