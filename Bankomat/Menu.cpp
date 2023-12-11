#include "Menu.h"

void Bankomat::Menu::CreateAccountMenu()
{
	system("cls");

	std::cout << "������� �����" << std::endl;
	std::string login;
	std::cin >> login;

	if (_banc.FindLogin(login))
	{
		std::cout << "����� ������������ ��� ����������";
		_getch();
		return;
	}

	std::cout << "������� ������" << std::endl;
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
		std::cout << "���� � �������" << std::endl;
		std::cout << "������� �����" << std::endl;

		std::string tryLogin;
		std::cin >> tryLogin;

		if (_banc.FindLogin(tryLogin, _client))
		{
			int count = 3;

			while (runMenu)
			{
				std::cout << "������� ������" << std::endl;
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
						throw std::exception("������� ������������");

					system("cls");
					count--;
					std::cout << "������ �� ������, �������� ������� " << count + 1 << std::endl;
					std::cout << "������� ����� ������� ��� �����������...";
					char choose = _getch();
					if (choose == 'q')
						runMenu = false;
					system("cls");
				}

			}

		}
		else
		{
			std::cout << "������ ������������ �� ����������\n���� ������ �����, ������� q";
			char choose = _getch();
			if (choose == 'q')
				break;
		}
	}
}

void Bankomat::Menu::replenishMenu()
{
	std::cout << "������� ������ �����" << std::endl;
	float amount;
	std::cin >> amount;

	if (amount <= 0 || std::cin.fail())
	{
		std::cout << "��� ������";
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
	std::cout << "������� ������ �����" << std::endl;

	float amount;
	std::cin >> amount;

	if (amount <= 0 || std::cin.fail())
	{
		std::cout << "��� ������";
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
		std::cout << "�� ������� �����" << std::endl;
		std::cout << "��� ������ " << _client->account.GetMoney() << " ������" << std::endl;
		std::cout << "����� ������ ����� " << _client->account.GetNumber() << std::endl;

		std::cout << "��������, ��� ������ �������:\n1 - ���������\n2 - ����� ������\nq - �����" << std::endl;
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
