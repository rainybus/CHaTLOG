#pragma once
#include <string>
#include <vector>

using namespace std;

class User
{
public:
	User() = default; // �ܬ�߬����ܬ��� ��� ��ެ�ݬ�Ѭ߬ڬ�
	~User() = default; // �լ֬����ܬ���

	User(const string& login_user, const string& name_user, const string& password_user) : _login(login_user), _name(name_user), _password(password_user) {} // �ܬ�߬����ܬ��� �� ��Ѭ�Ѭެ֬��Ѭެ�

	void setUserLogin(const string& login);
	string& getUserLogin();
	void setUserName(const string& name);
	string& getUserName();
	void setUserPassword(const string& password);
	string& getUserPassword();

private:
	string _login; // ��֬�֬ެ֬߬߬Ѭ� �� �ݬ�Ԭڬ߬��
	string _name; // ��֬�֬ެ֬߬߬Ѭ� �� �ڬެ֬߬֬�
	string _password; // ��֬�֬ެ֬߬߬Ѭ� �� ��Ѭ��ݬ֬�
};


void registr_new_user(vector<User>& U_V_C, string login_user, string name_user, string password_user);
