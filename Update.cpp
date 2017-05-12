#include "Update.h"


Update::Update()
{
}


Update::~Update()
{
}

Update::Update(char _type, float _money , float _remMoney, string _date) :type(_type), money(_money),remMoney(_remMoney), date(_date)
{}
string Update::getUpdateInformation()const{
	string result = "";
	string typeOfUpdate = (type == 'w') ? "withdrawn " : "deposited ";
	result = "At " + date + " you have " + typeOfUpdate
		+ std::to_string(money)+" L.E\n"
		+ "Your account now has " + std::to_string(remMoney)+" L.E\n";
	return result;
}