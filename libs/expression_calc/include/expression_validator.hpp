#pragma once

#include <iostream>
#include <cmath>

namespace expression_calc
{
    struct  xInvalidInputParams {};

    class ExpressionValidator
    {
    public:
        static void check(const double& a, const double& b, const double& x);
    };
}
