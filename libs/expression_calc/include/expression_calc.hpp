#pragma once

#include <iostream>
#include <cmath>

namespace expression_calc {
    class ExpressionCalculator {
        double a;
        double b;
    public:
        ExpressionCalculator(const double& a_, const double& b_): a(a_), b(b_) {}

        [[nodiscard]] double compute(const double &x) const;

        double operator()(const double &x) const {
            return compute(x);
        }

        friend std::ostream &operator<<(std::ostream &os, const ExpressionCalculator &expr);
    };

    std::ostream& operator<<(std::ostream& os, const ExpressionCalculator& expr);
}

