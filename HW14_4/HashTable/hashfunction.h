#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

#include <QObject>

class HashFunction
{
public:
    /// Class for hash function with fixed prime but variable size
    HashFunction(int initPrime);
    int hash(QString &str, int size) const;

private:
    int prime;
};

#endif // HASHFUNCTION_H
