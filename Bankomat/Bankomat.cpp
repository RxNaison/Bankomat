#include "Menu.h"

using namespace Bankomat;

int main()
{
	setlocale(LC_ALL, "ru");

    Menu menu;
    bool runApp = true;
    try
    {
        while (runApp)
        {
            system("cls");

            std::cout << "Здаров" << std::endl;
            std::cout << "Выберите, что хотите сделать:\n1 - создать аккаунт\n2 - войти\nq - выйти" << std::endl;
            char choose = _getch();
            switch (choose)
            {
            case '1':
                menu.CreateAccountMenu();
                break;
            case '2':
                menu.EnterInAccountMenu();
                break;
            case 'q':
                runApp = false;
                break;
            default:
                system("cls");
                std::cout << "Введено неверное значение" << std::endl;
                _getch();
                break;
            }

        }
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

	return 0;
}


