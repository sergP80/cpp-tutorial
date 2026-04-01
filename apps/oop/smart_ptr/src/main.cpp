#include "app.hpp"

#include <memory>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::fixed;
using std::setw;

using client_bank::Bank;
using client_bank::BankOffice;
using client_bank::Address;
using client_bank::builder::PersonalBuilder;

int main() {
    
    /*Address * r1 = new Address();

    Address * r2 = r1;

    r1 = nullptr;*/

    {
        std::shared_ptr<Address> p_addr_1 = std::make_shared<Address>("UA", "Mykolayivska oblast", "Mykolayiv", "Shoseyna (Frunze)", "20/a", "54112");

        cout << p_addr_1.use_count() << endl;

        {
            std::shared_ptr<Address> p_addr_2 = p_addr_1;
            cout << p_addr_1.use_count() << endl;

            cout << *p_addr_2 << endl;
        }

        cout << p_addr_1.use_count() << endl;

        cout << p_addr_1->get_city() << endl;
    }

    {
        std::unique_ptr<Address> p_addr_1 = std::make_unique<Address>("UA", "Mykolayivska oblast", "Mykolayiv", "Shoseyna (Frunze)", "20/a", "54112");
        std::unique_ptr<Address> p_addr_2 = std::move(p_addr_1);

        cout << *p_addr_2 << endl;
    }

    return 0;
}
