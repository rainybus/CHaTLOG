#pragma once
#include <string>
#include <vector>
using namespace std;

class Message
{
public:
	Message() = default; // �ܬ�߬����ܬ��� ��� ��ެ�ݬ�Ѭ߬ڬ�
	~Message() = default; // �լ֬����ܬ���


	Message(const string& login_user, const string& name_current_reciption, const string& message_current) : _sender(login_user), _recipient(name_current_reciption), _message(message_current) {} // �ܬ�߬����ܬ��� �� ��Ѭ�Ѭެ֬��Ѭެ�


	void setMessage(string message);
	string getMessage() const;

	void setSender(string sender);
	string getSender() const;

	void setRecipient(string recipient);
	string getRecipient() const;


private:
	string _sender; // �ݬ�Ԭڬ� �����ѬӬڬ�֬ݬ�
	string _recipient; // �ݬ�Ԭڬ� ���ݬ��Ѭ�֬ݬ�
	string _message; // ��֬ܬ�� ����Ҭ�֬߬ڬ�
};

void sent_message(vector<Message>& M_V_C, string login_user, string name_current_reciption, string message_current);