#include "CStandardAcc.h"

CStandardAcc::CStandardAcc(double i, const unsigned long int iban, unsigned qtl,  currency c)
	: IAccount(STANDARD, iban, i, qtl, c)
{
}

int CStandardAcc::loan()
{
	
	return 0;
}

void CStandardAcc::updateAccStatus()
{

}

std::ostream& operator<< (std::ostream& os, CStandardAcc& acc)
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

std::istream& operator>> (std::istream& is, CStandardAcc& acc)
{
	unsigned long int iban;
	is >> *(dynamic_cast<IAccount*>(&acc));
	is >> iban;

	if(iban)
		acc.associateSavingsAcc(iban);
	
	return is;
}
CStandardAcc::~CStandardAcc(void)
{
}