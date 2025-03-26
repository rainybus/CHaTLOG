#pragma once
#include <string>
#include <vector>

using namespace std;

class User
{
public:
	User() = default; // ¬Ü¬à¬ß¬ã¬ä¬â¬å¬Ü¬ä¬à¬â ¬á¬à ¬å¬Þ¬à¬Ý¬é¬Ñ¬ß¬Ú¬ð
	~User() = default; // ¬Õ¬Ö¬ã¬ä¬â¬å¬Ü¬ä¬à¬â

	User(const string& login_user, const string& name_user, const string& password_user) : _login(login_user), _name(name_user), _password(password_user) {} // ¬Ü¬à¬ß¬ã¬ä¬â¬å¬Ü¬ä¬à¬â ¬ã ¬á¬Ñ¬â¬Ñ¬Þ¬Ö¬ä¬â¬Ñ¬Þ¬Ú

	void setUserLogin(const string& login);
	string& getUserLogin();
	void setUserName(const string& name);
	string& getUserName();
	void setUserPassword(const string& password);
	string& getUserPassword();

private:
	string _login; // ¬á¬Ö¬â¬Ö¬Þ¬Ö¬ß¬ß¬Ñ¬ñ ¬ã ¬Ý¬à¬Ô¬Ú¬ß¬à¬Þ
	string _name; // ¬á¬Ö¬â¬Ö¬Þ¬Ö¬ß¬ß¬Ñ¬ñ ¬ã ¬Ú¬Þ¬Ö¬ß¬Ö¬Þ
	string _password; // ¬á¬Ö¬â¬Ö¬Þ¬Ö¬ß¬ß¬Ñ¬ñ ¬ã ¬á¬Ñ¬â¬à¬Ý¬Ö¬Þ
};


void registr_new_user(vector<User>& U_V_C, string login_user, string name_user, string password_user);
