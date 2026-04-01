#pragma once

#include <iostream>
#include <string>
#include "address.hpp"

namespace client_bank
{
    class Bank
    {
        std::string number;

        std::string name;

        Address address;

    public:
        Bank() = default;

        [[nodiscard]] Bank(const std::string& number, const std::string& name, const Address& address)
            : number(number),
              name(name),
              address(address)
        {
        }

        [[nodiscard]] std::string get_number() const
        {
            return number;
        }

        [[nodiscard]] std::string get_name() const
        {
            return name;
        }

        [[nodiscard]] Address get_address() const
        {
            return address;
        }

        friend std::ostream& operator<<(std::ostream& os, const Bank& bank);
    };

    inline std::ostream& operator<<(std::ostream& os, const Bank& bank)
    {
        os << "Bank {";
        os << "name: " << bank.name;
        os << ", number: " << bank.number;
        os << ", address: " << bank.address;
        os << "}";
        return os;
    }
}
