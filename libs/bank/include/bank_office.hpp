#pragma once

#include <iostream>
#include <string>
#include "bank.hpp"
#include "address.hpp"

namespace client_bank
{
	class BankOffice
	{
		int id;

		Address address;

		const Bank& bank;

	public:
		BankOffice(int id, const Address& address, const Bank& bank)
			: id(id),
			  address(address),
			  bank(bank)
		{
		}

		[[nodiscard]] int get_id() const
		{
			return id;
		}

		[[nodiscard]] Address get_address() const
		{
			return address;
		}

		void set_address(const Address& address)
		{
			this->address = address;
		}

		[[nodiscard]] Bank get_bank() const
		{
			return bank;
		}

		friend std::ostream& operator<<(std::ostream& os, const BankOffice& bo);
	};

	inline std::ostream& operator<<(std::ostream& os, const BankOffice& bo)
	{
		os << "Bank office {";
		os << "id: " << bo.id;
		os << ", address: " << bo.address;
		os << ", bank: " << bo.bank;
		os << "}";
		return os;
	}
}