#include "Account.h"
int Account::numOfIds = 100000;
float Account ::sumOfMoney = 0.0;
Account::Account(){ deactivated = false; }
Account::Account(string _name, float _money, string _date) :name(_name), money(_money), date(_date)
{
	deactivated = false;
	id = numOfIds++;
	Update update('c', 0.0, money, date);
	updates.push_back(update);
	sumOfMoney += _money;
}


Account::~Account(){}


void Account::addMoney(float _money,string date)
{
	money += _money;
	Update update('d', _money, money, date);
	  updates.push_back(update);
	  sumOfMoney += _money;
	
}
bool Account::withdrawMoney(float _money, string date)
{
	if ((money - _money) < 0)
		return false;

	money -= _money;
	Update update('w', _money, money, date);
	updates.push_back(update);
	sumOfMoney -= _money;
	return true;
}
bool Account::transferMoney(float _money, string date, Account & secondAccount){
	if ((money - _money) < 0)
		return false;
	money -= _money;
	Update update('t',secondAccount, _money, money, date);
	updates.push_back(update);
	secondAccount.recieveMoney(_money, date, *this);
	return true;
}
void Account::recieveMoney(float _money, string date, Account & Account){
	money += _money;
	Update update('v',Account, _money, money, date);
	updates.push_back(update);

}
void Account::deactivateAccount(string _date)
{
	deactivated = true;
	Update update('r', 0.0, 0.0, _date);
	updates.push_back(update);
}
string Account::getAllUpdates()
{
	string result = "Bank Statement ::\n";
	for (int i = 0; i < updates.size(); i++)
		result += updates[i].getUpdateInformation()+"\n";
	
	return result;
}


string Account::getName()const
{
	return name;
}


int Account::getAccountId()const
{
	return id;
}


bool Account::getDeactivatedFlag() const
{
	return deactivated;
}



float Account::getAccountMoney()const{ return money; }
bool operator <(Account a, Account b){
	return a.getAccountId() < b.getAccountId();
}
 float Account:: getBankMoney(){
	 return sumOfMoney;
}