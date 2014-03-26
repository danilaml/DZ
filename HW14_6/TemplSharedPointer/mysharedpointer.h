#ifndef MYSHAREDPOINTER_H
#define MYSHAREDPOINTER_H

template<typename T>
class MySharedPointer
{
public:
    MySharedPointer(T* pt);
    T* get() const;
};

#endif // MYSHAREDPOINTER_H
