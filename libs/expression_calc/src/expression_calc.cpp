#include "expression_calc.hpp"

namespace expression_calc {
    double ExpressionCalculator::compute(const double &x) const {

        using std::sin;
        using std::abs;
        using std::log;

        auto s = a*x - b * log(abs(2*x - a));
        auto t = sin(a*x + b*abs(cos(3 - x)));

        return (t - 2*s)/(abs(x - a) + s);
    }

}
