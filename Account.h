#pragma once
#include<string>
#include<vector>
#include"Update.h"
using std::string;
using std::vector;
class Account
{
	//static int numOfIds;
	string name;
	//int id;
	//string date;//start of account

	float money;
	vector<Update> updates;
public:
	Account();
	~Account();

	bool addMoney(float _money,string date);
	bool withdrawMoney(float _money, string date);
	
	string getAllUpdates();
};

