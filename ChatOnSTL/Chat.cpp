#include "Chat.h"
#include"User.h"
#include"Message.h"
#include<vector>
#include<iostream>
using namespace std;

void Chat::Chatting()
{
	Message mes;
	string nameTo, text;
	cout << "Enter username for chatting or 'all' for send message all of users: ";
	cin>> nameTo;
	cout << "Enter you message: ";
	cin.ignore();
	getline(cin, text);
	mes.setNameTo(nameTo);
	mes.setMessage(text);
	mes.setNameFrom(currentUser_->getName());
	Messages.push_back(mes);
}
void Chat::ReadMessage()
{
	for (auto& mess : Messages)
	{
		if (mess.getNameTo() == currentUser_->getName())
		{
			cout <<mess.getNameFrom()<< ": " << mess.getMessage() << endl;
		}
		if (mess.getNameTo() == "all")
		{
			cout << "For all users in chat: " << mess.getMessage() << endl;
		}
	}
}
void Chat::NewUser(const string& name, const string& pass)
{
	for (auto& us : Users)
	{
		if (us.getName() == name)
		{
			cout << "Username is taken" << endl;
			return;
		}
	}
	User user(name, pass);
	Users.push_back(user);	
}

bool Chat::Auth(const string& name, const string& pass)
{
	for (auto& us : Users)
	{
		if (us.getName() == name && us.getPass() == pass)
		{
			currentUser_ = make_shared <User>(us);
			cout << "Authorized" << endl;
			system("pause");
			system("cls");
			return true;
		}
	}	
	cout << "Invalid authorization data" << endl;
	system("pause");
	system("cls");
	return false;
}

void Chat::ShowUsers()
{
	cout << "Users in chat: " << endl;
	for (auto& users : Users)
	{
		cout << users.getName() << endl;
	}
}