#ifndef MYEMPTYLISTEXCEPTION_H
#define MYEMPTYLISTEXCEPTION_H

#include "myexception.h"

class MyEmptyListException : public MyException
{
public:
    MyEmptyListException(const char *msg);
};

#endif // MYEMPTYLISTEXCEPTION_H
