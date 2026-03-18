#include "app.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::fixed;
using std::setw;

int main() {
    
    int a1[] = { 1, -3, 5, 8, -4 };

    int sz = sizeof(a1) / sizeof(a1[0]);

    auto min1 = min(a1, sz);


    cout << "min: " << min1 << endl;


    {
        int min1, max1;

        min_max(a1, sz, min1, max1);

        cout << "min: " << min1  << "\tmax: " << max1 << endl;

    }

    {
        Employee employees[] = {
            {1, 12901.87, "john doe"},
            {2, 47791.68, "sam altman"},
            {3, 438891424.349, "bill w. geits"},
        };

        Employee min1, max1;

        min_max(employees, min1, max1);

        cout << min1 << endl;
        cout << max1 << endl;
    }

    {
        int origin = -3;

        double g = 1.15;

        auto sum1 = [&](const int& a, const int& b)
        {
            return origin + a + b;
        };

        int a = 5, b = -7;

        cout << sum1(a, b) << endl;

        origin = 10;

        cout << sum1(-8, 12) << endl;

        constexpr std::array<int, 6> list1 {-1, 2, 5, 7, -4, 11};

        auto res = std::find_if(list1.begin(), list1.end(), [](const auto& i) { return i == 12; });

        if (res != list1.end())
        {
            cout << "Item found: " << *res << endl;
        }
        else
        {
            cout << "Item not found" << endl;
        }

        auto res_2 = std::all_of(list1.begin(), list1.end(), [](const auto& i) { return i < 20; });

        cout << "Is has any item great then 20? : " << std::boolalpha << res_2 << endl;

        auto res_3 = std::all_of(list1.begin(), list1.end(), [](const auto& i) { return i > 0; });

        cout << "Is array contains all positives? : " << std::boolalpha << res_3 << endl;

        auto res_4 = std::any_of(list1.begin(), list1.end(), [](const auto& i) { return i > 0; });

        cout << "Is array contains any positives? : " << std::boolalpha << res_4 << endl;

        auto summator = [origin](const double& a, const double& b)
            {
                return origin + a + b;
            };

        auto res_d1 = expr_calc(3.5, 5, [origin](const double& a, const double& b) {return origin + a + b; });

        cout << "Summator: " << res_d1 << endl;
    }

    return 0;
}
