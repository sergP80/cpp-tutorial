#include <iostream>
#include <iomanip>
#include "address.hpp"
#include "bank.hpp"
#include "bank_office.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::fixed;
using std::setw;

using client_bank::Bank;
using client_bank::BankOffice;
using client_bank::Address;

int main() {
    
    Address address1 {"UA", "Mykolayivska oblast", "Mykolayiv", "Shoseyna (Frunze)", "20/a", "54112"};

    using client_bank::builder::AddressBuilder;

    auto address2 = AddressBuilder::builder()
    .country_code("UA")
    .city("Mykolayiv")
    .zip("54116")
    .street("Budivelnikiv")
    .build_number("14")
    .build();

    cout << address1 << endl;
    cout << address2 << endl;

    return 0;
}
