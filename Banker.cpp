#include "Banker.h"


Banker::Banker()
{
}


Banker::~Banker()
{
}


bool Banker::makeDeposit(Account & account, float money, string date)
{
	if (!account.getDeactivatedFlag()){
		account.addMoney(money, date);
		return true;
	}
	return false;
}
int Banker::withdraw(Account & account, float money, string date)
{
	if (!account.getDeactivatedFlag()){
		if (account.withdrawMoney(money, date))
			return 1;//done
		else
			return 0;//no enough money
	}
	return -1;//deactivated account
}



string Banker::requestAccountRecordsList(Account & account)
{
	string result = account.getAllUpdates();
	return result;
}
int Banker::transfer(Account & firstAccount, Account & secondAccount, float money, string date){
	if (!firstAccount.getDeactivatedFlag())
		return -1;//source acc deactivated
	else if (!secondAccount.getDeactivatedFlag())
		return -2;//destination acc deactivated
	else if (firstAccount.transferMoney(money, date, secondAccount))
		return 1;//done
	else 
		return 0;//no enough money
}




bool Banker::deactivateAccount(Account & account,string _date)
{ if (account.getDeactivatedFlag())
	return false;//already deactivated before
  else 
    account.deactivateAccount(_date);
     return true;
}
