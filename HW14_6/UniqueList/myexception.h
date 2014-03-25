#ifndef EXCEPTION_H
#define EXCEPTION_H

class MyException
{
    /// Basic class for exception with error message
public:
    MyException(const char* msg);
    const char* const message;
};

#endif // EXCEPTION_H
