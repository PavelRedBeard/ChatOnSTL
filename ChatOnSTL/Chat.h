#pragma once
#include"User.h"
#include"Message.h"
#include<vector>
#include<iostream>
using namespace std;

class Chat
{
public:
	void Chatting();
	void ReadMessage();	
	void ShowUsers();
	void NewUser(const string& name, const string& pass);
	bool Auth(const string& name, const string& pass);
	shared_ptr <User> currentUser_ = nullptr;
private:	
	vector <Message> Messages;
	vector <User> Users;	
};

