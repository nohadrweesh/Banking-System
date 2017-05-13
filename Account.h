#pragma once
#include<string>
#include<vector>
#include"Update.h"
using std::string;
using std::vector;
class Update;
class Account
{
	static int numOfIds;
	static float sumOfMoney;
	string name;
	int id;
	
	string date;//start of account
	bool deactivated;
	float money;
	vector<Update> updates;
public:
	Account();
	Account(string _name,float _money,string _date);
	~Account();

	void addMoney(float _money, string date);
	bool withdrawMoney(float _money, string date);
	bool transferMoney(float _money, string date, Account & secondAccount);
	void recieveMoney(float _money, string date, Account & Account);
	string getAllUpdates();
	string getName() const;
	int getAccountId() const;
	bool getDeactivatedFlag() const;
	float getAccountMoney()const;
	void deactivateAccount(string _date);
	static float getBankMoney();
};
bool operator <(Account a, Account b);
