
#include "expression_validator.hpp"

namespace expression_calc
{
    void ExpressionValidator::check(const double& a, const double& b, const double& x)
    {
        if (2*x - a < 0)
        {
            throw xInvalidInputParams {};
        }
    }
}
