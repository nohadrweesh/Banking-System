#pragma once
#include<string>
using std::string;
class Update
{
private:
	char type;//d  or w
	float money;
	float remMoney;
	string date;
public:
	Update();
	Update(char _type, float _money, float _remMoney,string _date);
	string getUpdateInformation()const;
	~Update();
};

