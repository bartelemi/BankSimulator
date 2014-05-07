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
	BankManager(BankManager const&);    //nie implementowaæ
	void operator=(BankManager const&); //nie implementowaæ
	
	std::string fileNameprefix;

	//kontenery na dane
	TQueue<unsigned long> IBANs;
	TQueue<IAccount> accounts;
	TQueue<CTransaction> pendingTransactions;
	TQueue<CTransaction> completedTransactions;

	~BankManager(void);
public:
	//dostêp do singletona tylko przez t¹ metodê
	static BankManager& getInstance();

	void initialize(std::string fName);

	void showAcc();
};
