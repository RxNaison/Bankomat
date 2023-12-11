#pragma once
#include "Account.h"

namespace Bankomat
{
	class Client
	{
	public:
		Client(std::string login, std::string password);
		Client();
		std::string GetLogin();

		Account account;

		bool CheckPass(std::string password);
	private:
		std::string _password;
		std::string Login;
	};
}


