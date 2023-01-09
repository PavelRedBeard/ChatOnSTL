#pragma once
#include<string>
using namespace std;

class User
{
public:
	User(const string& name, const string& pass) : _name(name), _pass(pass) {}
	~User() = default;
	void setName(const string& name);
	void setPass(const string& pass);
	string getName() const;
	string getPass() const;	
private:	
	string _name;
	string _pass;	
};