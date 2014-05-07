#pragma once

#include "IAccount.h"
#include "IAccountManagement.h"

#include "types.h"

class CSavingsAcc :
	public IAccount
{
public:
	CSavingsAcc(double i = 0.0, const unsigned long int iban = 0,
		        unsigned qtl = 0, currency c = PLN);

	int payIn();
	int payOut();

	void updateAccStatus();

	friend std::ostream& operator<< (std::ostream& os, IAccount& acc);
	friend std::istream& operator>> (std::istream& is, IAccount& acc);

	friend IAccount* loadAcc(std::ifstream& f);

	~CSavingsAcc(void);
};

class CInvestition
{
public:
	CInvestition();

	int payIn();
	int payOut();

	~CInvestition();
};