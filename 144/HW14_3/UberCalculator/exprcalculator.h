#ifndef EXPRCALCULATOR_H
#define EXPRCALCULATOR_H
#include <QObject>

class ExprCalculator
{
    /// It's a class that contains methods for parsing expression (QString) and calculating it
public:
    static double calculateExpr(const QString &expr);

private:
    /// Calculate postfix expr.
    static double calculatePostfixExpr(const QString &expr);
    /// Convert infix expression to postfix expr.
    static QString toPostfix(const QString &expr);
};

#endif // EXPRCALCULATOR_H
