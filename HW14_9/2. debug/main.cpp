#include <iostream>
#include "stackByHeap.h"
#include "calculator.h"

using namespace std;

void stackIsEmpty(AbstractStack<int>* stack)
{
    cout << "Now stack ";
    if (stack->isEmpty())
        cout << "is empty";
    else
        cout << "isn't empty";
    cout << endl;
}

void stackTest()
{
    cout << "Stack test:" << endl;
    AbstractStack<int>* stack = new StackByHeap<int>;
    stackIsEmpty(stack);

    const int iter = 3;
    for (int i = 0; i < iter; ++i)
    {
        cout << "Enter value ";
        int val;
        cin >> val;
        cout << " push " << val << endl;
        stack->push(val);
    }
    stackIsEmpty(stack);
    for (int i = 0; i < iter; ++i)
    {
        cout << "Top element: " << stack->top() << endl;
        cout << "Pop element: " << stack->pop() << endl;
    }
    stackIsEmpty(stack);
    delete stack;
}

int main()
{
    Calculator* calc = new Calculator;
    calc->test();

    return 0;
}

