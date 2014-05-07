#include "OtherAccounts.h"

CSavingsAcc::CSavingsAcc(double i, const unsigned long int iban, unsigned qtl, currency c)
	: IAccount(SAVINGS, iban, i, qtl, c)
{
}

int CSavingsAcc::payIn()
{
	return 0;
}
int CSavingsAcc::payOut()
{
	return 0;
}

std::ostream& operator<< (std::ostream& os, CSavingsAcc& acc)
{
	os << *(dynamic_cast<IAccount*>(&acc));
	os << std::endl;
	return os;
}

std::istream& operator>> (std::istream& is, CSavingsAcc& acc)
{
	is >> *(dynamic_cast<IAccount*>(&acc));
	return is;
}

CSavingsAcc::~CSavingsAcc(void)
{

}

CInvestition::CInvestition()
{

}

int CInvestition::payIn()
{
	return 0;
}

int CInvestition::payOut()
{
	return 0;
}

CInvestition::~CInvestition()
{
}

