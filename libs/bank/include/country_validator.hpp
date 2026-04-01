#pragma once

#include <string>
#include <exception>

namespace client_bank
{
    struct xInvalidCountryCode : std::exception
    {
    };

    class CountryCodeValidator
    {
    public:
        static void validate(const std::string& country_code)
        {
            if (country_code.empty())
            {
                throw xInvalidCountryCode();
            }

            if (country_code.size() < 2 || country_code.size() > 3)
            {
                throw xInvalidCountryCode();
            }
        }
    };
}
