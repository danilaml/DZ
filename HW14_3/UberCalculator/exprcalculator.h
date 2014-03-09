#ifndef EXPRCALCULATOR_H
#define EXPRCALCULATOR_H
#include <QObject>

class ExprCalculator
{
public:
    static double calculateExpr(const QString &expr);

private:
    static double calculatePostfixExpr(const QString &expr);
    static QString toPostfix(const QString &expr);
};

#endif // EXPRCALCULATOR_H
