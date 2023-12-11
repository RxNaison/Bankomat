#include "Menu.h"

void Bankomat::Menu::CreateAccountMenu()
{
	system("cls");

	std::cout << "Введите логин" << std::endl;
	std::string login;
	std::cin >> login;

	if (_banc.FindLogin(login))
	{
		std::cout << "Такой пользователь уже существует";
		_getch();
		return;
	}

	std::cout << "Введите пароль" << std::endl;
	std::string password;
	std::cin >> password;

	_banc.AddAccount(Client(login, password));
}

void Bankomat::Menu::EnterInAccountMenu()
{
	bool runMenu = true;
	while (runMenu)
	{
		system("cls");
		std::cout << "Вход в аккаунт" << std::endl;
		std::cout << "Введите логин" << std::endl;

		std::string tryLogin;
		std::cin >> tryLogin;

		if (_banc.FindLogin(tryLogin, _client))
		{
			int count = 3;

			while (runMenu)
			{
				std::cout << "Введите пароль" << std::endl;
				std::string tryPass;
				std::cin >> tryPass;

				if ((*_client).CheckPass(tryPass))
				{
					userMenu();
					runMenu = false;
				}
				else
				{
					if (count <= 0)
						throw std::exception("Аккаунт заблокирован");

					system("cls");
					count--;
					std::cout << "Пароль не верный, осталось попыток " << count + 1 << std::endl;
					std::cout << "Нажмите любую клавишу для продолжения...";
					char choose = _getch();
					if (choose == 'q')
						runMenu = false;
					system("cls");
				}

			}

		}
		else
		{
			std::cout << "такого пользователя не существует\nесли хотите выйти, нажмите q";
			char choose = _getch();
			if (choose == 'q')
				break;
		}
	}
}

void Bankomat::Menu::replenishMenu()
{
	std::cout << "Введите нужную сумму" << std::endl;
	float amount;
	std::cin >> amount;

	if (amount <= 0 || std::cin.fail())
	{
		std::cout << "иди лечись";
		std::cin.clear();
		std::cin.ignore();
		_getch();

	}
	else
	{
		_client->account.replenish(amount);
	}
}

void Bankomat::Menu::payMenu()
{
	std::cout << "Введите нужную сумму" << std::endl;

	float amount;
	std::cin >> amount;

	if (amount <= 0 || std::cin.fail())
	{
		std::cout << "иди лечись";
		_getch();
	}
	else
	{
		_client->account.Pay(amount);
	}
}

void Bankomat::Menu::userMenu()
{
	bool runMenu = true;
	while (runMenu)
	{
		system("cls");
		std::cout << "Вы успешно вошли" << std::endl;
		std::cout << "Ваш баланс " << _client->account.GetMoney() << " рублей" << std::endl;
		std::cout << "Номер вашего счета " << _client->account.GetNumber() << std::endl;

		std::cout << "Выберите, что хотите сделать:\n1 - пополнить\n2 - снять деньги\nq - выйти" << std::endl;
		char choose = _getch();
		switch (choose)
		{
		case '1':
			replenishMenu();
			break;
		case '2':
			payMenu();
			break;
		case 'q':
			_client = nullptr;
			runMenu = false;
			break;
		}

	}
}
