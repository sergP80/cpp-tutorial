#include <sstream>

#include "address.hpp"

namespace client_bank
{
	std::string Address::to_string() const
	{
		std::stringstream ss;

		ss << zip <<", " << buildNumber << ", " << street << ", " << city <<", " << region << ", " << country_code;

		return ss.str();
	}
}