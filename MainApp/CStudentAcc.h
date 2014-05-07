#pragma once

#include "IAccount.h"
#include "IAccountManagement.h"
#include "OtherAccounts.h"

class CStudnetAcc :
	public IAccount, public IAccountManagement
{
private:
	void PayBack();
	CSavingsAcc* mySavings;

public:
	CStudnetAcc(double i = 0.0, const unsigned long int iban = 0,
		        unsigned qtl = 0, currency c = PLN);

	int topUp();
	int studentLoan();
	
	void updateAccStatus();

	friend std::ostream& operator<< (std::ostream& os, CStudnetAcc& acc);
	friend std::istream& operator>> (std::istream& is, CStudnetAcc& acc);

	~CStudnetAcc(void);
};
