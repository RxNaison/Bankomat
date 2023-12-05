using System;

namespace Bankomat
{
    internal class Account
    {
        public string Number { get; private set; }
        public float Money { get; private set; } = 0;

        public Account()
        {
            Random random = new Random();

            for (int i = 0; i < 10; i++)
                Number += random.Next(10);
        }


        public void replenish(float amountMoney)
        {
            if (amountMoney <= 0)
                throw new InvalidOperationException("Ты кого наебать пытаешься");
            Money += amountMoney;
        }

        private bool CheckSolvency(float amountMoney)
        {
            if (amountMoney <= 0)
                return false;

            return Money >= amountMoney;
        }

        public void Pay(float amountMoney)
        {
            if (CheckSolvency(amountMoney))
            {
                Money -= amountMoney;
            }
            else
            {
                Console.WriteLine("Денег не хватает");
                Console.ReadKey();
            }

        }
    }
}
