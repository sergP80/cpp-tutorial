#include "bank_group.hpp"

namespace client_bank
{
    int BankGroup::instance_count = 0;

    BankGroup& BankGroup::create(const std::string& name)
    {
        static BankGroup instance;

        instance.set_name(name);

        return instance;
    }
}
