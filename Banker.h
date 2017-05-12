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
	static bool withdraw(Account & account, float money, string date);
	string requestAccountRecordsList(Account & account) const;
};

