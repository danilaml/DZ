#ifndef MYOUTOFRANGEEXCEPTION_H
#define MYOUTOFRANGEEXCEPTION_H


#include "myexception.h"

class MyOutOfRangeException : public MyException
{
public:
    MyOutOfRangeException(const char *msg);
};

#endif // MYOUTOFRANGEEXCEPTION_H
