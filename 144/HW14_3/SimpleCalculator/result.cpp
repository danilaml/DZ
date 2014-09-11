#include "result.h"

QString Result::recalculate(int larg, int rarg, int actionIndex)
{
    QString res = "";
    switch (actionIndex)
    {
    case 0:
        res.setNum(larg + rarg);
        break;
    case 1:
        res.setNum(larg - rarg);
        break;
    case 2:
        res.setNum(larg * rarg);
        break;
    case 3:
        (rarg == 0) ? (res = "DvZ") : res.setNum(larg / rarg);
        break;
    }

    return res;
}
