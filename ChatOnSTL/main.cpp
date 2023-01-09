#include<string>
#include<iostream>
#include<conio.h>
#include"Chat.h"
using namespace std;

int main()
{	
	Chat chat;
	string ex;
	while (!(ex == "Yes") && !(ex == "yes"))
	{
		cout << "\t" << "----------Welcome to Chat----------" << endl;
		cout << "\t" << "What would you like to do:" << "\n" << "1: NewUser" << "\n" << "2: Auth" << "\n" << "3: Exit" << endl;
		int choise;
		cin >> choise;
		switch (choise)
		{
		case 1:
		{			
			string uname, upass;
			cout << "Enter Username: ";
			cin >> uname;
			cout << "\n";
			cout << "Enter password: ";
			cin >> upass;
			cout << "\n";
			system("cls");
			chat.NewUser(uname, upass);
			break;
		}
		case 2:
		{
			string uname, upass;
			cout << "Enter Username: ";
			cin >> uname;
			cout << "\n";
			cout << "Enter password: ";
			cin >> upass;
			cout << "\n";
			system("cls");
			if (chat.Auth(uname, upass) == true)
			{
				string exit;
				while (!(exit == "Yes") && !(exit == "yes"))
				{
					cout<< "\t" << "----------Personal menu----------" << endl;
					cout << "\t" << "What would you like to do:" << "\n" << "1: Chatting" << "\n" << "2: Read messages for you" << "\n" << "3: Exit" << endl;
					int ch;
					cin >> ch;
					switch (ch)
					{
					case 1:
					{
						chat.ShowUsers();
						chat.Chatting();
						system("cls");
						break;
					}					
					case 2:
					{
						chat.ReadMessage();
						system("pause");
						break;
					}
					case 3:
					{
						cout << "Input 'yes' to confirm exit" << endl;
						cin >> exit;
						break;
					}
					default:
						break;
					}
					system("cls");
				}
			}
			else
			{				
				break;
			}
			break;
		}
		case 3:
		{
			cout << "Input 'yes' to confirm exit" << endl;
			cin >> ex;
			break;
		}
		default:
			break;
		}		
	}
	return 0;
};