#include "CBusinessAcc.h"

CBusinessAcc::CBusinessAcc(double i, const unsigned long int iban, unsigned qtl,  currency c)
	: IAccount( BUSINESS, iban, i, qtl, c)
{

}

int CBusinessAcc::bussinesLoan()
{
	
	return 0;
}

int CBusinessAcc::foreignTransfer()
{
	
	return 0;
}

int CBusinessAcc::officialTransfer()
{
	
	
	return 0;
}

int CBusinessAcc::changeCurrency()
{
	
	
	return 0;
}

void CBusinessAcc::updateAccStatus()
{

}

std::ostream& operator<< (std::ostream& os, CBusinessAcc& acc)
{
	//Zapisanie wpierw konta oszczêdnoœciowego
	if(acc.mySavings)
		os << acc.mySavings;

	//zapisanie inwestycji
	//if(acc.myInvestitions)
	//	os << acc.myInvestitions;

	os << *(dynamic_cast<IAccount*>(&acc));

	if(acc.mySavings)
		os << acc.mySavings->getIBAN();
	else 
		os << "0";

	os << std::endl;

	return os;
}

std::istream& operator>> (std::istream& is, CBusinessAcc& acc)
{
	unsigned long int iban;
	is >> *(dynamic_cast<IAccount*>(&acc));
	is >> iban;

	if(iban)
		acc.associateSavingsAcc(iban);
	
	return is;
}

CBusinessAcc::~CBusinessAcc(void)
{

}