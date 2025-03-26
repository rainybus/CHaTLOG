#pragma once
#include <string>
#include <vector>
using namespace std;

class Message
{
public:
	Message() = default; // ¬Ü¬à¬ß¬ã¬ä¬â¬å¬Ü¬ä¬à¬â ¬á¬à ¬å¬Þ¬à¬Ý¬é¬Ñ¬ß¬Ú¬ð
	~Message() = default; // ¬Õ¬Ö¬ã¬ä¬â¬å¬Ü¬ä¬à¬â


	Message(const string& login_user, const string& name_current_reciption, const string& message_current) : _sender(login_user), _recipient(name_current_reciption), _message(message_current) {} // ¬Ü¬à¬ß¬ã¬ä¬â¬å¬Ü¬ä¬à¬â ¬ã ¬á¬Ñ¬â¬Ñ¬Þ¬Ö¬ä¬â¬Ñ¬Þ¬Ú


	void setMessage(string message);
	string getMessage() const;

	void setSender(string sender);
	string getSender() const;

	void setRecipient(string recipient);
	string getRecipient() const;


private:
	string _sender; // ¬Ý¬à¬Ô¬Ú¬ß ¬à¬ä¬á¬â¬Ñ¬Ó¬Ú¬ä¬Ö¬Ý¬ñ
	string _recipient; // ¬Ý¬à¬Ô¬Ú¬ß ¬á¬à¬Ý¬å¬é¬Ñ¬ä¬Ö¬Ý¬ñ
	string _message; // ¬ä¬Ö¬Ü¬ã¬ä ¬ã¬à¬à¬Ò¬ë¬Ö¬ß¬Ú¬ñ
};

void sent_message(vector<Message>& M_V_C, string login_user, string name_current_reciption, string message_current);