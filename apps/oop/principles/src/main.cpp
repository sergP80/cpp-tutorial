#include <iostream>
#include <iomanip>
#include "address.hpp"
#include "bank.hpp"
#include "bank_office.hpp"
#include "personal.hpp"

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
    
    Address address1 {"UA", "Mykolayivska oblast", "Mykolayiv", "Shoseyna (Frunze)", "20/a", "54112"};

    using client_bank::builder::PersonalBuilder;

    auto address2 = client_bank::builder::AddressBuilder::builder()
    .country_code("UA")
    .city("Mykolayiv")
    .zip("54116")
    .street("Budivelnikiv")
    .build_number("14")
    .build();

    auto personal = PersonalBuilder::builder()
    .first_name("James")
    .middle_name("Lebron")
    .last_name("Ivanov")
    .birth_date("06.07.1982")
    .gender("Male")
    .build();

    cout << personal << endl;
    cout << address1 << endl;
    cout << address2 << endl;
    return 0;
}
