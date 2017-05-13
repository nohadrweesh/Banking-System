#include "Update.h"


Update::Update()
{
}


Update::~Update()
{
}

Update::Update(char _type, Account &secondAccount, float _money = 0.0, float _remMoney = 0.0, string _date = "")
	:type(_type), money(_money), remMoney(_remMoney), date(_date), transferAccount(&secondAccount)
{}
Update::Update(char _type, float _money = 0.0, float _remMoney = 0.0, string _date="")
	: type(_type), money(_money), remMoney(_remMoney), date(_date){}
string Update::getUpdateInformation()const{
	string result = "";
	//d  or w or t or v or r or c
	if (type == 'c')//created
	{
		result = "At " + date + " you have create your account \n"
				+ "Your account now has " + std::to_string(remMoney) + " L.E\n";
	}
	else if (type == 'd')//deposit
	{
		result = "At " + date + " you have deposited to your account " 
			+ std::to_string(money) + " L.E\n"
			+ "Your account now has " + std::to_string(remMoney) + " L.E\n";
	}
	else if (type == 'w')//withdraw
	{
		result = "At " + date + " you have withdrawn "
			+ std::to_string(money) + " L.E\n"
			+ "Your account now has " + std::to_string(remMoney) + " L.E\n";
	}
	else if (type == 't')//transfer
	{
		result = "At " + date + " you have deposited" + std::to_string(money) + " L.E\n"" to " + transferAccount->getName()
			+ " Account number : " + std::to_string(transferAccount->getAccountId()) 
			+ "\nYour account now has " + std::to_string(remMoney) + " L.E\n";
	}
	else if (type == 'v')//someone transfered money to you(recieved)
	{
		result = "At " + date + " you have received " + std::to_string(money) + " L.E\n"+" from " + transferAccount->getName()
			+ " Account number : " + std::to_string(transferAccount->getAccountId())
			+ "\nYour account now has " + std::to_string(remMoney) + " L.E\n";
	}
	else if (type == 'r')//delete account
	{
		result = "At " + date + " you have deactivated your account \n You can't use it any more.\n";
			
	}
	/*string typeOfUpdate = (type == 'w') ? "withdrawn " : "deposited ";
	result = "At " + date+ " you have " + typeOfUpdate
		+ std::to_string(money)+" L.E\n"
		+ "Your account now has " + std::to_string(remMoney)+" L.E\n";*/
	return result;
}