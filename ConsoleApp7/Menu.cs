using System;


namespace Bankomat
{
    internal class Menu
    {
        private Client _client;
        private Banc _banc = new Banc();

        public void CreateAccountMenu()
        {
            Console.Clear();

            Console.WriteLine("Введите логин");
            string login = Console.ReadLine();

            Console.WriteLine("Введите пароль");
            string password = Console.ReadLine();
            
            _banc.AddAccount(new Client(login, password));
        }

        public void EnterInAccountMenu()
        {
            bool runMenu = true;
            while (runMenu)
            {
                Console.Clear();
                Console.WriteLine("Вход в аккаунт");

                Console.WriteLine("Введите логин");
                string tryLogin = Console.ReadLine();

                if (_banc.FindLogin(tryLogin, ref _client))
                {
                    int count = 3;
                    
                    while (runMenu)
                    {
                        Console.WriteLine("Введите пароль");
                        string tryPass = Console.ReadLine();

                        if (_client.CheckPass(tryPass))
                        {
                            userMenu();
                            runMenu = false;
                        }
                        else
                        {
                            if (count <= 0)
                                throw new InvalidOperationException("Аккаунт заблокирован");

                            Console.Clear();
                            count--;
                            Console.WriteLine("Пароль не верный, осталось попыток " + count);
                            Console.WriteLine("Нажмите любую клавишу для продолжения...");
                            char choose = Console.ReadKey(true).KeyChar;
                            if (choose == 'q')
                                runMenu = false;
                        }

                    }

                }
                else
                {
                    Console.WriteLine("такого пользователя не существует\nесли хотите выйти, нажмите q");
                    char choose = Console.ReadKey(true).KeyChar;
                    if (choose == 'q')
                        break;
                }
            }
        }

        private void replenishMenu()
        {
            Console.WriteLine("Введите нужную сумму");
            float amount = float.Parse(Console.ReadLine());
            if (amount <= 0)
            {
                Console.WriteLine("иди лечись");
                Console.ReadKey();
            }
            else
            {
                _client.Account.replenish(amount);
            }
        }
        private void payMenu()
        {
            Console.WriteLine("Введите нужную сумму");
            float amount = float.Parse(Console.ReadLine());
            if (amount <= 0)
            {
                Console.WriteLine("иди лечись");
                Console.ReadKey();
            }
            else
            {
                _client.Account.Pay(amount);
            }
        }

        private void userMenu()
        {
            bool runMenu = true;
            while (runMenu)
            {
                Console.Clear();
                Console.WriteLine("Вы успешно вошли");
                Console.WriteLine("Ваш баланс " + _client.Account.Money + " рублей");
                Console.WriteLine("Номер вашего счета " + _client.Account.Number);

                Console.WriteLine("Выберите, что хотите сделать:\n1 - пополнить\n2 - снять деньги\nq - выйти");
                char choose = Console.ReadKey(true).KeyChar;
                switch (choose)
                {
                    case '1':
                        replenishMenu();
                        break;
                    case '2':
                        payMenu();
                        break;
                    case 'q':
                        runMenu = false;
                        break;
                }
            
            }
        }
    }
}
