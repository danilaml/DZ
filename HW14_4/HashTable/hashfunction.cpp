#include "hashfunction.h"

HashFunction::HashFunction(int initPrime) : prime(initPrime)
{
}

int HashFunction::hash(QString &str, int size) const
{
    int res = 0;
    for (int i = 0; i < str.length(); i++)
    {
        res = (res * prime  + str[i].toLatin1()) % size;
    }

    return res;
}
