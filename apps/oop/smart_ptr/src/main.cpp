#include "app.hpp"

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

    {
        using smart_ptr::UniquePtr;

        UniquePtr<int> ptr1 = smart_ptr::make_unique<int>(210);

        cout << *ptr1 << endl;

        UniquePtr<int[]> array = smart_ptr::make_unique_array<int>(10);

        for (int i = 0; i < array.length(); ++i)
        {
            array[i] = i + 1;
        }

        for (int i = 0; i < array.length(); ++i)
        {
            cout << array[i] << endl;
        }
    }

    {
        using smart_ptr::SharedPtr;

        SharedPtr<int> p_count = smart_ptr::make_shared<int>(25);
    }

    return 0;
}
