#include "Client.h"

Bankomat::Client::Client(std::string login, std::string password)
{
    _password = password;
    Login = login;
}

Bankomat::Client::Client()
{
    _password = "";
    Login = "";
}

std::string Bankomat::Client::GetLogin()
{
    return Login;
}

bool Bankomat::Client::CheckPass(std::string password)
{
    return _password == password;
}
