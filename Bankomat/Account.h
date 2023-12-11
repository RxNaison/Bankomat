#pragma once
#include <string>
#include <ctime>
#include <exception>
#include <conio.h>
#include <iostream>

namespace Bankomat
{
    class Account
    {
    public:
        Account();

        std::string GetNumber();
        float GetMoney();

        void replenish(float amountMoney);
        bool CheckSolvency(float amountMoney);
        void Pay(float amountMoney);
    private:
        std::string Number;
        float Money = 0;
    };
}



