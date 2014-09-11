#ifndef EXCEPTION_H
#define EXCEPTION_H

/// Basic class for exception with error message
class MyException
{
public:
    MyException(const char* msg);
    const char* get() const;

private:
    const char* const message;
};

#endif // EXCEPTION_H
