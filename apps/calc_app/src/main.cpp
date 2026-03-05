#include "app.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::fixed;
using std::setw;

int main() {
    using expression_calc::ExpressionCalculator;

    cout << "Enter expression constant a, b:";

    double a, b;
    cin >> a >> b;

    ExpressionCalculator calculator{a, b};

    cout << "Enter range of calculation [from, to, step]:";

    double from, to, step;

    cin >> from >> to >> step;

    cout << setw(10) << "x";
    cout << setw(10) << "result" << endl;

    for (auto x = from; x <= to; x += step) {
        auto result = calculator(x);

        cout << setw(10) << setprecision(5) << fixed << x;
        cout << setw(10) <<setprecision(5) << fixed << result << endl;
    }
}
