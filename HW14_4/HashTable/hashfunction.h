#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

#include <QObject>

class HashFunction
{
public:
    HashFunction(int initPrime);
    int hash(QString &str, int size) const;

private:
    int prime;
};

#endif // HASHFUNCTION_H
