#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

#include "types.h"

class IAccount
{
private:
	accountType accType;
	unsigned long long int accNumber;
	currency myCurrency;
	double balance;
	double interest;
	unsigned int quickTransferLimit;

public:
	IAccount(accountType aType, const unsigned long int iban, double i, unsigned qtl,  currency c);
	
	inline accountType getType() const { return accType; }
	inline  unsigned long long int getIBAN() const { return accNumber; }
	inline currency getCurrency() const { return myCurrency; }
	inline double getBalance() const { return balance; }
	inline double getInterest() const { return interest; }
	inline unsigned int getQuickTransferLimit() const { return quickTransferLimit; }

	void accountInfo();

	friend std::ostream& operator<< (std::ostream& os, IAccount& acc);
	friend std::istream& operator>> (std::istream& is, IAccount& acc);

	friend IAccount* loadAcc(std::ifstream& f);
	friend std::string saveAcc(IAccount* object);

	virtual ~IAccount(void);
};
