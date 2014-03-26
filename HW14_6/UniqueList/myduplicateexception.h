#ifndef MYDUPLICATEEXCEPTION_H
#define MYDUPLICATEEXCEPTION_H

#include "myexception.h"

class MyDuplicateException : public MyException
{
public:
    MyDuplicateException(const char *msg);
};

#endif // MYDUPLICATEEXCEPTION_H
