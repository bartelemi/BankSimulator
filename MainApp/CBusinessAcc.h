#pragma once

#include "IAccount.h"
#include "IAccountManagement.h"
#include "OtherAccounts.h"

class CBusinessAcc :
	public IAccount, public IAccountManagement
{
private:
	CSavingsAcc* mySavings;
	CInvestition* myInvestitions;

public:
	CBusinessAcc(double i = 0.0, const unsigned long int iban = 0, 
		         unsigned qtl = 0, currency c = PLN);

	int bussinesLoan();
	int foreignTransfer();
	int officialTransfer();
	int changeCurrency();

	void updateAccStatus();

	friend std::ostream& operator<< (std::ostream& os, CBusinessAcc& acc);
	friend std::istream& operator>> (std::istream& is, CBusinessAcc& acc);

	~CBusinessAcc(void);
};

