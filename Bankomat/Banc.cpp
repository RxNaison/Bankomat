#include "Banc.h"

void Bankomat::Banc::AddAccount(Client client)
{
	_accounts[client.GetLogin()] = client;
}

bool Bankomat::Banc::FindLogin(std::string tryLogin, Client*& client)
{
	bool ans = _accounts.count(tryLogin);

	if(ans)
	client = (&_accounts.at(tryLogin));

	return ans;
}

bool Bankomat::Banc::FindLogin(std::string tryLogin)
{
	return _accounts.count(tryLogin);
}
