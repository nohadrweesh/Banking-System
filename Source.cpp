#include<iostream>
#include <ctime>
#include "Banker.h"
#include"Account.h"
#include<set>
using namespace std;

int main() {
	/*// current date/time based on current system
	time_t now = time(0);

	// convert now to string form
	char* dt = ctime(&now);

	cout << "The local date and time is: " << dt << endl;

	// convert now to tm struct for UTC
	tm *gmtm = gmtime(&now);
	dt = asctime(gmtm);
	cout << "The UTC date and time is:" << dt << endl;*/
	set<Account*>db;
	Account nohaAccount = Banker::createAccount("noha mahmoud", 200, "Sat Jan  8 20:07 : 41 2011");
	Account ayaAccount = Banker::createAccount("aya mahmoud", 400, "Sat Jan  8 20:07 : 41 2015");
	Account islamAccount = Banker::createAccount("islam mahmoud", 500, "Sat Jan  8 20:07 : 41 2012");
	Account emanAccount = Banker::createAccount("eman mahmoud", 1000, "Sat Jan  8 20:07 : 41 2013");
	db.insert(&nohaAccount); db.insert(&ayaAccount); db.insert(&islamAccount);
	db.insert(&emanAccount);
	cout << Banker::checkBalance(nohaAccount);
	Banker::makeDeposit(nohaAccount, 50, "Sat May  8 20:07 : 41 2011");
	Banker::makeDeposit(nohaAccount, 100, "Sat May  10 20:07 : 41 2012");
	Banker::transfer(nohaAccount, ayaAccount, 100, "Sat May  10 20:07 : 41 2016");
	Banker::withdraw(islamAccount, 150, "11-2-2011");
	Banker::deactivateAccount(emanAccount, "11-2-2014");
	Banker::transfer(nohaAccount, emanAccount, 50, "11-2-2015");
	
	

	cout<<Banker::requestAccountRecordsList(nohaAccount);

	cout << Banker::checkBalance(nohaAccount);
	cout << Banker::requestAccountRecordsList(ayaAccount);
	cout << Banker::requestAccountRecordsList(islamAccount); 
		cout << Banker::requestAccountRecordsList(emanAccount);
	system("pause");
}