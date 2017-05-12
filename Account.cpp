#include "Account.h"


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
	money += _money;
	Update update('d', _money, money, date);
	updates.push_back(update);
	return true;
	return false;
}

