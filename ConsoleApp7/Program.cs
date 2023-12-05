using System;

namespace Bankomat
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Menu menu = new Menu();
            bool runApp = true;
            try
            {
                while (runApp)
                {
                    Console.Clear();

                    Console.WriteLine("Здаров");
                    Console.WriteLine("Выберите, что хотите сделать:\n1 - создать аккаунт\n2 - войти\nq - выйти");
                    char choose = Console.ReadKey(true).KeyChar;
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
                            Console.Clear();
                            Console.WriteLine("Введено неверное значение");
                            Console.ReadKey();
                            break;
                    }

                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }


        }
    }
}
