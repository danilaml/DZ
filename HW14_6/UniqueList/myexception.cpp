#include "myexception.h"

MyException::MyException(const char *msg) : message(msg)
{
}

const char* MyException::get() const
{
    return message;
}
