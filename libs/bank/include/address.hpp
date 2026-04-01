#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "country_validator.hpp"

namespace client_bank
{
    class AddressBuilder;

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

        [[nodiscard]] Address(const std::string& country_code,
                              const std::string& city,
                              const std::string& street,
                              const std::string& zip)
            : country_code(country_code),
              region(""),
              city(city),
              street(street),
              buildNumber(""),
              zip(zip)
        {
        }

        [[nodiscard]] Address(const std::string& address)
        {
            std::stringstream ss(address);
            std::getline(ss, this->buildNumber, ',');
            std::getline(ss, this->street, ',');
            std::getline(ss, this->city, ',');
            std::getline(ss, this->country_code, ',');
            std::getline(ss, this->zip, ',');
        }

        [[nodiscard]] Address(const char* address) : Address(std::string(address))
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

        friend class AddressBuilder;
    };

    inline std::ostream& operator<<(std::ostream& os, const Address& address)
    {
        os << address.to_string();
        return os;
    }

    namespace builder
    {
        class AddressBuilder
        {
            Address result;
            AddressBuilder() = default;
        public:
            static AddressBuilder builder()
            {
                return {};
            }

            AddressBuilder& country_code(const std::string& country_code)
            {
                this->result.set_country_code(country_code);
                return *this;
            }

            AddressBuilder& region(const std::string& region)
            {
                this->result.set_region(region);
                return *this;
            }

            AddressBuilder& city(const std::string& city)
            {
                this->result.set_city(city);
                return *this;
            }

            AddressBuilder& street(const std::string& street)
            {
                this->result.set_street(street);
                return *this;
            }

            AddressBuilder& build_number(const std::string& build_number)
            {
                this->result.set_build_number(build_number);
                return *this;
            }

            AddressBuilder& zip(const std::string& zip)
            {
                this->result.set_zip(zip);
                return *this;
            }

            Address build()
            {
                return result;
            }
        };
    }
}
