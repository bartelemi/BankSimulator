#include "IAccountManagement.h"


IAccountManagement::IAccountManagement(void)
{
}

void IAccountManagement::associateSavingsAcc(unsigned long int iban)
{

}

int IAccountManagement::transfer(unsigned int IBAN)
{

	return 0;
}

int IAccountManagement::quickTransfer(unsigned int IBAN)
{

	return 0;
}

int IAccountManagement::wireTransfer(unsigned int IBAN)
{

	return 0;
}

int IAccountManagement::cancelWireTransfer(unsigned int IBAN)
{

	return 0;
}

int IAccountManagement::directDebit(unsigned int IBAN)
{

	return 0;
}

int IAccountManagement::cancelDirectDebit(unsigned int IBAN)
{

	return 0;
}

IAccountManagement::~IAccountManagement(void)
{
}
