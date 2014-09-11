#ifndef MYSHAREDPOINTER_H
#define MYSHAREDPOINTER_H

/// Template class for basic implementation of shared pointer
template<typename T>
class MySharedPointer
{
public:
    MySharedPointer() : stored(new pstorage())
    {
    }

    MySharedPointer(T *pt) :stored(new pstorage(pt))
    {
    }

    MySharedPointer(MySharedPointer const &spt) : stored(spt.stored)
    {
        stored->count++;
    }

    ~MySharedPointer()
    {
        stored->count--;
        if (stored->count <= 0)
        {
            delete stored;
        }
    }

    T* get() const
    {
        return stored->ptr;
    }

    int useCount() const
    {
        return stored->count;
    }

    MySharedPointer& operator=(MySharedPointer const &stp)
    {
        if (stored != stp.stored)
        {
            stored->count--;
            stored = stp.stored;
            stored->count++;
        }
        return *this;
    }

private:
    struct pstorage
    {
        pstorage() : ptr(nullptr), count(0)
        {
        }

        pstorage(T *pt) : ptr(pt), count(1)
        {
        }

        ~pstorage()
        {
            delete ptr;
        }

        T *ptr;
        int count;
    };

    pstorage* stored;
};

#endif // MYSHAREDPOINTER_H
