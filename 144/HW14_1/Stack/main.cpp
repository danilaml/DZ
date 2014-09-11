#include <iostream>
#include "myarraystack.h"
#include "stacktest.h"

using namespace std;

int calculateExpr(const char* expr, int explen, MyStack *stack);

int main()
{
    StackTest stktest;
    QTest::qExec(&stktest);

    cout << endl;

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
    mas->printStack();

    const char* s = "10 15 2 * +";
    cout << calculateExpr(s,11,mas);

    delete mas;

    return 0;
}

int calculateExpr(const char* expr, int explen, MyStack *stack)
{
    for (int i = 0; i < explen; i++)
    {
        if ((expr[i] >= '0') && (expr[i] <= '9'))
        {
            int num = 0;
            while ((i < explen) && (expr[i] >= '0') && (expr[i] <= '9'))
            {
                num = (num * 10) + (expr[i] - '0');
                i++;
            }
            stack->push(num);
            i--;
            continue;
        }

        if (expr[i] == ' ')
        {
            continue;
        }
        int rightarg,leftarg;
        if(expr[i] == '-' || expr[i] == '+' || expr[i] == '*' || expr[i] == '/')
        {
            rightarg = stack->pop();
            leftarg = stack->pop();
        }
        if (expr[i] == '+')
        {
            stack->push(leftarg + rightarg);
            continue;
        }
        if (expr[i] == '-')
        {
            stack->push(leftarg - rightarg);
            continue;
        }
        if (expr[i] == '*')
        {
            stack->push(leftarg * rightarg);
            continue;
        }
        if (expr[i] == '/')
        {
            stack->push(leftarg / rightarg);
            continue;
        }
    }
    return stack->back();
}
