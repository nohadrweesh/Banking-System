#pragma once
#include<string>
#include<vector>
#include"Update.h"
using std::string;
using std::vector;
class Account
{
	float money;
	string date;
	vector<Update> updates;
public:
	Account();
	~Account();

	bool addMoney(float _money,string date);
	bool withdrawMoney(float _money, string date);
};

