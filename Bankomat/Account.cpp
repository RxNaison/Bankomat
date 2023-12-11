#include "Account.h"


    Bankomat::Account::Account()
    {
        srand(time(nullptr));

        for (int i = 0; i < 10; i++)
            Number += std::to_string(rand() % 10);
    }

    std::string Bankomat::Account::GetNumber()
    {
        return Number;
    }

    float Bankomat::Account::GetMoney()
    {
        return Money;
    }

    void Bankomat::Account::replenish(float amountMoney)
    {
        if (amountMoney <= 0)
            throw std::exception("Ты кого наебать пытаешься");

        Money += amountMoney;
    }

    bool Bankomat::Account::CheckSolvency(float amountMoney)
    {
        if (amountMoney <= 0)
            return false;

        return Money >= amountMoney;
    }

    void Bankomat::Account::Pay(float amountMoney)
    {
        if (CheckSolvency(amountMoney))
        {
            Money -= amountMoney;
        }
        else
        {
            std::cout << "Денег не хватает";
            _getch();
        }
    }


