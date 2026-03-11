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


    cout << "Min: " << min1 << endl;


    {
        int min1, max1;

        min_max(a1, sz, min1, max1);

        cout << "Min: " << min1  << "\tMax: " << max1 << endl;

    }

    {

        Employee employees[] = {
            {1, 12901.87, "John Doe"},
            {2, 47791.68, "Sam Altman"},
            {3, 438891424.349, "Bill W. Geits"},
        };

        Employee min1, max1;

        min_max(employees, min1, max1);

        cout << min1 << endl;
        cout << max1 << endl;
    }

    return 0;
}
