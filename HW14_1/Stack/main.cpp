#include <iostream>
#include <myarraystack.h>

using namespace std;

int main()
{
    MyArrayStack *mas = new MyArrayStack(100);
    mas->push(0);
    mas->push(1);
    mas->push(2);
    mas->push(3);
    mas->push(3);
    mas->push(3);
    mas->printStack();
    cout << mas->pop() << endl;
    mas->printStack();
    cout << mas->back() << endl;
    mas->printStack();
    mas->clear();
    //mas.pop;

    return 0;
}

