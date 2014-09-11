#include "num.h"

Num::Num(int numb) : num(numb)
{
}

int Num::compute() const
{
    return num;
}

std::string Num::toString() const
{
    return (std::to_string(num));
}
