#include <iostream>
#include "myhashtable.h"

using namespace std;

int main()
{
    MyHashTable *mht = new MyHashTable(10000);

    QString a = "abc";
    QString b = "abcabc";
    QString c = "abracadabra";
    QString d = "ololo";

    mht->add(a);
    mht->add(a);
    mht->add(b);
    mht->add(c);
    mht->add(d);

    mht->print();

    delete mht;

    return 0;
}

