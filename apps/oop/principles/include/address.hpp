#pragma once

#include <iostream>
#include <string>
#include "country_validator.hpp"

namespace client_bank
{
    class Address
    {
        std::string country_code;
        std::string region;
        std::string city;
        std::string street;
        std::string buildNumber;
        std::string zip;

    public:
        Address() = default;

        [[nodiscard]] Address(const std::string& country_code,
                              const std::string& region,
                              const std::string& city,
                              const std::string& street,
                              const std::string& build_number,
                              const std::string& zip)
            : country_code(country_code),
              region(region),
              city(city),
              street(street),
              buildNumber(build_number),
              zip(zip)
        {
        }

        [[nodiscard]] const std::string& get_country_code() const
        {
            return country_code;
        }

        void set_country_code(const std::string& country_code)
        {
            CountryCodeValidator::validate(country_code);

            this->country_code = country_code;
        }

        [[nodiscard]] const std::string& get_region() const
        {
            return region;
        }

        void set_region(const std::string& region)
        {
            this->region = region;
        }

        [[nodiscard]] const std::string& get_city() const
        {
            return city;
        }

        void set_city(const std::string& city)
        {
            this->city = city;
        }

        [[nodiscard]] const std::string& get_street() const
        {
            return street;
        }

        void set_street(const std::string& street)
        {
            this->street = street;
        }

        [[nodiscard]] const std::string& get_build_number() const
        {
            return buildNumber;
        }

        void set_build_number(const std::string& build_number)
        {
            buildNumber = build_number;
        }

        [[nodiscard]] const std::string& get_zip() const
        {
            return zip;
        }

        void set_zip(const std::string& zip)
        {
            this->zip = zip;
        }

        [[nodiscard]] std::string to_string() const;
    };

    inline std::ostream& operator<<(std::ostream& os, const Address& address)
    {
        os << address.to_string();
        return os;
    }
}
