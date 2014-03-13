#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <QObject>

class MyHashTable
{
    /// HashTable class with basic hashtable methods
public:
    MyHashTable();
    MyHashTable(int initSize);
    ~MyHashTable();
    void add(QString &str);
    bool contains(QString &str) const;
    int tableSize() const;
    int loadFactor() const;
    int numberOfConflicts() const;
    int biggestConflitSize() const;
    void changeHashFunc(int newConst, int newSize);
    void print() const;

private:
    int hash(QString &str) const;
    std::list<QString> *ar;
    int size;
    int prime;
};

#endif // MYHASHTABLE_H
