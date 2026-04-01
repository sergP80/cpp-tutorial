#pragma once

#include <iostream>
#include <string>

namespace client_bank
{
    namespace builder { class PersonalBuilder; }

    class Personal
    {
        std::string first_name;
        std::string middle_name;
        std::string last_name;
        std::string birth_date;
        std::string gender;

    public:
        std::string to_string() const;
        friend class builder::PersonalBuilder;
    };

    inline std::ostream& operator<<(std::ostream& os, const Personal& personal)
    {
        os << personal.to_string();
        return os;
    }

    namespace builder
    {
        class PersonalBuilder
        {
            Personal result;
            PersonalBuilder() = default;
        public:
            static PersonalBuilder builder() {
                return {};
            }

            PersonalBuilder& first_name(const std::string& first_name)
            {
                result.first_name = first_name;
                return *this;
            }

            PersonalBuilder& middle_name(const std::string& middle_name)
            {
                result.middle_name = middle_name;
                return *this;
            }

            PersonalBuilder& last_name(const std::string& last_name)
            {
                result.last_name = last_name;
                return *this;
            }

            PersonalBuilder& birth_date(const std::string& birth_date)
            {
                result.birth_date = birth_date;
                return *this;
            }

            PersonalBuilder& gender(const std::string& gender)
            {
                result.gender = gender;
                return *this;
            }

            Personal build()
            {
                return result;
            }
        };
    }
}