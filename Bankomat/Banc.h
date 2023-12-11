#pragma once
#include <unordered_map>
#include "Client.h"

namespace Bankomat
{
	class Banc
	{
	public:
		void AddAccount(Client client);
		bool FindLogin(std::string tryLogin, Client*& client);
		bool FindLogin(std::string tryLogin);
	private:
		std::unordered_map<std::string, Client> _accounts;
	};
}



