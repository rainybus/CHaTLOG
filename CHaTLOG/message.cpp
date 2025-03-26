#include <iostream>
#include <vector>
#include <string>
#include "message.h"
using namespace std;

string Message::getMessage() const
{
	return _message;
}

void Message::setMessage(string message)
{
	_message = message;
}

string Message::getSender() const
{
	return _sender;
}

void Message::setSender(string sender)
{
	_sender = sender;
}

string Message::getRecipient() const
{
	return _recipient;
}

void Message::setRecipient(string recipient)
{
	_recipient = recipient;
}

void sent_message(vector<Message>& M_V_C, string login_user, string name_current_reciption, string message_current)
{
	M_V_C.push_back(Message(login_user, name_current_reciption, message_current)); // ¬Õ¬à¬Ò¬Ñ¬Ó¬İ¬ñ¬Ö¬Ş ¬ß¬à¬Ó¬í¬Û ¬à¬Ò¬ì¬Ö¬Ü¬ä Message
}
