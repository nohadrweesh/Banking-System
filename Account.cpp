#include "Account.h"
//int Account::numOfIds = 0;

Account::Account()
{
}


Account::~Account()
{
}


bool Account::addMoney(float _money,string date)
{
	money += _money;
	  Update update('d', _money,money, date);
	  updates.push_back(update);
	  return true;
	return false;
}
bool Account::withdrawMoney(float _money, string date)
{
	if ((money - _money) < 0)
		return false;

	money -= _money;
	Update update('w', _money, money, date);
	updates.push_back(update);
	return true;
}



string Account::getAllUpdates()
{
	string result = "Bank Statement ::\n";
	for (int i = 0; i < updates.size(); i++)
		result += updates[i].getUpdateInformation();
	
	return result;
}
