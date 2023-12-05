namespace Bankomat
{
    internal class Client
    {
        
        public Account Account;
        private string _password;
        public string Login {  get; private set; }

        public Client(string login, string password)
        {
            _password = password;
            Account = new Account();
            Login = login;
        }

        public bool CheckPass(string password)
        {
            return _password == password;
        }
    }
}
