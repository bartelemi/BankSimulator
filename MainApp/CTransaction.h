#pragma once

#include <iostream>
#include <sstream>

#include "IAccount.h"
#include "types.h"

class CTransaction
{
private:
	IAccount* from;
	IAccount* to;
	double amount;
	transactionType tType;

	void associateAcc(unsigned long int iban, char dir);
public:
	CTransaction(IAccount* f = NULL, IAccount* t = NULL, double a = 0.0, transactionType tt = TRANSFER);

	void getFromInfo() const { from->accountInfo(); }
	void getToInfo() const { to->accountInfo(); }
	inline double getAmount() const { return amount; }
	inline transactionType getTransactionType() const { return tType; }

	void info() const;

	friend std::ostream& operator<< (std::ostream& os, CTransaction& tr);
	friend std::istream& operator>> (std::istream& is, CTransaction& tr);

	friend CTransaction* loadTran(std::ifstream& f);
	friend std::string saveTran(CTransaction* object);

	~CTransaction(void);
};

