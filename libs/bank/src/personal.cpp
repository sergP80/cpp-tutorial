#include <sstream>

#include "personal.hpp"

namespace client_bank
{
	std::string Personal::to_string() const
	{
		std::stringstream ss;

		ss << first_name <<", " << middle_name << ", " << last_name << ", " << birth_date;

		return ss.str();
	}
}