#pragma once
#include "IAccount.h"

class IAccount;

class IAccountManagement
{
protected:
	void associateSavingsAcc(unsigned long int iban);

public:
	IAccountManagement(void);
	
	int transfer(unsigned int IBAN);
	int quickTransfer(unsigned int IBAN);
	int wireTransfer(unsigned int IBAN);
	int cancelWireTransfer(unsigned int IBAN);
	int directDebit(unsigned int IBAN);
	int cancelDirectDebit(unsigned int IBAN);

	virtual void updateAccStatus() = 0;

	virtual ~IAccountManagement(void);

	friend IAccount;
};

