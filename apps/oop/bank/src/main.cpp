#include "app.hpp"
#include "bank_group.hpp"

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

using client_bank::BankGroup;

int main()
{
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

    {
        Address address = "54,V.Morska str.,Mykolayiv,UA,54210";
        cout << address << endl;
    }

    {
        Address address = std::string("68,Desantnikov str.,Mykolayiv,UA,54030");
        cout << address << endl;
    }

    BankGroup bank_group = BankGroup::create("A1");
    cout << bank_group << endl;

    BankGroup bank_group2 = BankGroup::create("A2");

    cout << bank_group << endl;
    cout << BankGroup::get_instance_count() << endl;
    return 0;
}
