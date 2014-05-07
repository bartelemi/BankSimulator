#pragma once

#include "IAccount.h"
#include "IAccountManagement.h"
#include "OtherAccounts.h"

class CStandardAcc :
	public IAccount, public IAccountManagement
{
private:
	CSavingsAcc* mySavings;

public:
	CStandardAcc(double i = 0.0, const unsigned long int iban = 0, 
				 unsigned qtl = 0, currency c = PLN);

	int loan();

	void updateAccStatus();

	friend std::ostream& operator<< (std::ostream& os, CStandardAcc& acc);
	friend std::istream& operator>> (std::istream& is, CStandardAcc& acc);

	~CStandardAcc(void);
};