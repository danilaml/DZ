#include "exprcalculator.h"
#include <stack>
#include <math.h>

double ExprCalculator::calculateExpr(const QString &expr)
{
    return calculatePostfixExpr(toPostfix(expr));
}

double ExprCalculator::calculatePostfixExpr(const QString &expr)
{
    std::stack<double> stk;
    for (int i = 0; i < expr.length(); i++)
    {
        if ((expr[i] >= '0') && (expr[i] <= '9'))
        {
            double num = 0;
            while (i < expr.length() && (expr[i] >= '0') && (expr[i] <= '9'))
            {
                num = (num * 10) + (expr[i].toLatin1() - '0');
                i++;
            }
            if(i < expr.length() && expr[i] == '.')
            {
                i++;
                double dnum = 0;
                double k = 0;
                while (i < expr.length() && (expr[i] >= '0') && (expr[i] <= '9'))
                {
                    dnum = (dnum * 10) + (expr[i].toLatin1() - '0');
                    i++;
                    k++;
                }
                num += dnum * pow(10, -k);
            }
            stk.push(num);
            i--;
            continue;
        }

        if (expr[i] == ' ')
        {
            continue;
        }
        double rightarg = 0;
        double leftarg = 0;
        if(expr[i] == '-' || expr[i] == '+' || expr[i] == '*' || expr[i] == '/')
        {
            rightarg = stk.top();
            stk.pop();
            leftarg = stk.top();
            stk.pop();
        }
        if (expr[i] == '+')
        {
            stk.push(leftarg + rightarg);
            continue;
        }
        if (expr[i] == '-')
        {
            stk.push(leftarg - rightarg);
            continue;
        }
        if (expr[i] == '*')
        {
            stk.push(leftarg * rightarg);
            continue;
        }
        if (expr[i] == '/')
        {
            stk.push(leftarg / rightarg);
            continue;
        }
    }
    return stk.top();
}

QString ExprCalculator::toPostfix(const QString &expr)
{
    std::stack<QChar> stk;
    QString res;
    for(int i = 0; i < expr.length(); i++)
    {
        if ((expr[i] >= '0') && (expr[i] <= '9'))
        {
            double num = 0;
            while (i < expr.length() && (expr[i] >= '0') && (expr[i] <= '9'))
            {
                num = (num * 10) + (expr[i].toLatin1() - '0');
                i++;
            }
            if(i < expr.length() && expr[i] == '.')
            {
                i++;
                double dnum = 0;
                double k = 0;
                while (i < expr.length() && (expr[i] >= '0') && (expr[i] <= '9'))
                {
                    dnum = (dnum * 10) + (expr[i].toLatin1() - '0');
                    i++;
                    k++;
                }
                num += dnum * pow(10, -k);
            }
            res.append(QString("%1 ").arg(num));
            i--;
            continue;
        }

        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            stk.push(expr[i]);
            continue;
        }
    }
    while(!stk.empty())
    {
        res.append(QString("%1 ").arg(stk.top()));
        stk.pop();
    }

    return res;
}
