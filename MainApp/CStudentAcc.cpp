#include "CStudentAcc.h"

CStudnetAcc::CStudnetAcc(double i, const unsigned long int iban, unsigned qtl, currency c)
	: IAccount(STUDENT, iban, i, qtl, c)
{
}

int CStudnetAcc::topUp()
{

	return 0;
}

int CStudnetAcc::studentLoan()
{

	return 0;
}

void CStudnetAcc::updateAccStatus()
{

}

std::ostream& operator<< (std::ostream& os, CStudnetAcc& acc)
{
	//Zapisanie wpierw konta oszczêdnoœciowego
	if(acc.mySavings)
		os << acc.mySavings;

	os << *(dynamic_cast<IAccount*>(&acc));
	if(acc.mySavings)
		os << acc.mySavings->getIBAN();
	else 
		os << "0";

	os << std::endl;
	return os;
}

std::istream& operator>> (std::istream& is, CStudnetAcc& acc)
{
	unsigned long int iban;
	is >> *(dynamic_cast<IAccount*>(&acc));
	is >> iban;

	if(iban)
		acc.associateSavingsAcc(iban);
	
	return is;
}

CStudnetAcc::~CStudnetAcc(void)
{
}

