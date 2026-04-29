#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "address.hpp"

namespace client_bank
{
    class BankGroup
    {
        std::string name;

        void set_name(const std::string& name)
        {
            this->name = name;
        }

        BankGroup()
        {
            ++instance_count;
        }

        static int instance_count;
    public:

        static BankGroup& create(const std::string& name);

        [[nodiscard]] std::string get_name() const
        {
            return name;
        }

        friend std::ostream& operator<<(std::ostream& os, const BankGroup& bank_group);

        static int get_instance_count()
        {
            return instance_count;
        }
    };

    inline std::ostream& operator<<(std::ostream& os, const BankGroup& bank_group)
    {
        os << "BankGroup {";
        os << "name: " << bank_group.name;
        os << "}";
        return os;
    }
}
