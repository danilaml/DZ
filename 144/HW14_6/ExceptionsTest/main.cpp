#include <iostream>

using namespace std;

class A
{
public:
    ~A() {cout << "A is destroyed" << endl;}
};

class B
{
public:
    ~B() {cout << "B is destroyed" << endl;}
};

class C
{
public:
    ~C() {cout << "C is destroyed" << endl;}
};

class Exec
{
public:
    ~Exec() {cout << "Exec is destroyed" << endl;}
};

int main()
{
    try
    {
        A a;
        B b;
        C c;
        throw Exec();
    }
    catch (...)
    {
        cout << "In catch" << endl;
    }
    return 0;
}

