using System;
using System.Collections.Generic;
namespace Bankomat
{
    internal class Banc
    {
        private Dictionary<string, Client> _accounts = new Dictionary<string, Client>();

        public void AddAccount(Client client)
        {
            _accounts.Add(client.Login, client);
        }
        public bool FindLogin(string tryLogin, ref Client client)
        {
            return _accounts.TryGetValue(tryLogin, out client);
        }
    }
}
