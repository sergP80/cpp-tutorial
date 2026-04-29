#include "expression_calc.hpp"
#include "expression_validator.hpp"

namespace expression_calc {
    double ExpressionCalculator::compute(const double &x) const {

        ExpressionValidator::check(a, b, x);

        using std::sin;
        using std::abs;
        using std::log;

        auto s = a*x - b * log(2*x - a);
        auto t = sin(a*x + b*abs(cos(3 - x)));

        return (t - 2*s)/(abs(x - a) + s);
    }

}
