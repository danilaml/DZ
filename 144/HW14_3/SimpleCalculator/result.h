#ifndef RESULT_H
#define RESULT_H
#include <QObject>

class Result
{
public:   
    /// Class with method to recalculate expression based on new args
    static QString recalculate(int larg, int rarg, int actionIndex);
};

#endif // RESULT_H
