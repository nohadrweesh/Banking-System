#pragma once
#include"Account.h"
#include<string>
using std::string;
class Banker
{

private:
	Banker();
	~Banker();
public:
	static bool makeDeposit(Account & account, float money, string date);
	static int withdraw(Account & account, float money, string date);
	static int transfer(Account & firstAccount, Account & secondAccount, float money, string date);
	
	
	static string requestAccountRecordsList(Account & account) ;
	static bool deactivateAccount(Account & account,string _date);
};

