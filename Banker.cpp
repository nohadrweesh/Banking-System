#include "Banker.h"


Banker::Banker()
{
}


Banker::~Banker()
{
}


bool Banker::makeDeposit(Account & account, float money, string date)
{
	if (account.addMoney(money, date))
		return true;
	return false;
}
bool Banker::withdraw(Account & account, float money, string date)
{
	if (account.withdrawMoney(money, date))
		return true;
	return false;
}



string Banker::requestAccountRecordsList(Account & account)const
{
	string result = "";
	return result;
}
