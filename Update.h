#pragma once
#include<string>
#include"Account.h"
using std::string;
class Account;
class Update
{
private:
	char type;//d  or w or t or v or r or c
	float money;
	float remMoney;
	string date;
	Account *transferAccount;
public:
	Update();
	//Update(char _type, float _money, float _remMoney, string _date);
	Update(char _type, Account &secondAccount, float _money, float _remMoney, string _date);
	Update(char _type, float _money, float _remMoney, string _date);

	string getUpdateInformation()const;
	~Update();
};

