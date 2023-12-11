#pragma once
#include "Client.h"
#include "Banc.h"

namespace Bankomat
{
	class Menu
	{
	public:
		void CreateAccountMenu();
		void EnterInAccountMenu();

	private:
		Client* _client = nullptr;
		Banc _banc;

		void replenishMenu();
		void payMenu();
		void userMenu();
	};
}

