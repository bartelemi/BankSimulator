#pragma once

#include <string>

#include "IAccount.h"
#include "CTransaction.h"
#include "IBAN.h"
#include "TQueue.h"
#include "TQueue.cpp"

/*
TODO:

*/

class BankManager
	:IAccountManagement
{
private:
	BankManager(void) {}				//prywatny konstruktor
	BankManager(BankManager const&);    //nie implementowa�
	void operator=(BankManager const&); //nie implementowa�
	
	std::string fileNameprefix;

	//kontenery na dane
	TQueue<unsigned long> IBANs;
	TQueue<IAccount> accounts;
	TQueue<CTransaction> pendingTransactions;
	TQueue<CTransaction> completedTransactions;

	~BankManager(void);
public:
	//dost�p do singletona tylko przez t� metod�
	static BankManager& getInstance();

	void initialize(std::string fName);

	void showAcc();
};
