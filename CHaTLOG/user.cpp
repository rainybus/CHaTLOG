#include <string>
#include <iostream>
#include <vector>
#include "user.h"

using namespace std;

string& User::getUserLogin()
{
	return _login;
}

void User::setUserLogin(const string& login)
{
	_login = login;
}

string& User::getUserName()
{
	return _name;
}

void User::setUserName(const string& name)
{
	_name = name;
}

string& User::getUserPassword()
{
	return _password;
}

void User::setUserPassword(const string& password)
{
	_password = password;
}


void registr_new_user(vector<User>& U_V_C, string login_user, string name_user, string password_user)
{
	U_V_C.push_back(User(login_user, name_user, password_user)); // ¬Õ¬à¬Ò¬Ñ¬Ó¬Ý¬ñ¬Ö¬Þ ¬ß¬à¬Ó¬í¬Û ¬à¬Ò¬ì¬Ö¬Ü¬ä User ¬Ó ¬Ó¬Ö¬Ü¬ä¬à¬â
	cout << "User " << name_user << " registered" << endl << endl;
}

