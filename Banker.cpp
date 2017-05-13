#include "Banker.h"


Banker::Banker()
{
}


Banker::~Banker()
{
}
Account & Banker::createAccount(string _name, float money, string date){
	Account *newAcc=new Account(_name, money, date);
	return * newAcc;
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
	string result = "";
	if (!account.getDeactivatedFlag())
	 result = account.getAllUpdates();
	return result;//result=""if deactivated
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
bool Banker:: requestLoan(float _money){
	if (Account::getBankMoney() / 8.0 >= _money)
		return true;//we'll see in our next meeting either to accept or refuse
	else
		return false;//refused
}
string Banker::checkBalance(Account & account){
	string result = "";
	if (!account.getDeactivatedFlag()){
		float money = account.getAccountMoney();
		result = "You have " + std::to_string(money) + " L.E\n";
	}
	return result;//result=""if it's deactivated
}