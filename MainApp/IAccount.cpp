#include "IAccount.h"
#include "CBusinessAcc.h"
#include "CStandardAcc.h"
#include "CStudentAcc.h"
#include "OtherAccounts.h"

using namespace std;

IAccount::IAccount(accountType aType, const unsigned long int iban, double i, unsigned qtl,  currency c)
	: accType(aType), accNumber(iban), myCurrency(c), balance(0.0), interest(i), quickTransferLimit(qtl)
{
}

void IAccount::accountInfo()
{
	cout << "IBAN: " << getIBAN() << endl;
	cout << "Saldo: " << getBalance();
	switch(myCurrency)
	{
	case PLN:
		cout << " PLN" << endl;
		break;
	case EUR:
		cout << " EUR" << endl;
		break;
	case GBP:
		cout << " GBP" << endl;
		break;
	default:
		cout << endl;
	}
	cout << "Oprocentowanie: " << getInterest() << "%" << endl;
	cout << "Pozostaly limit szybkich przelewow: " << getQuickTransferLimit() << endl;
}

ostream& operator<< (ostream& os, IAccount& acc)
{
	os << acc.getType() << endl;
	os << acc.getIBAN() << endl;
	os << acc.getCurrency() << endl;
	os << acc.getBalance() << endl;
	os << acc.getInterest() << endl;
	os << acc.getQuickTransferLimit() << endl;
	return os;
}

istream& operator>> (istream& is, IAccount& acc)
{
	is >> acc.accNumber;
	is >> acc.myCurrency;
	is >> acc.balance;
	is >> acc.interest;
	is >> acc.quickTransferLimit;

	return is;
}

std::string saveAcc(IAccount* object)
{
	stringstream ss;
	switch (object->accType)
	{
		case BUSINESS:
		ss << *(dynamic_cast<CBusinessAcc*>(object));
		break;
	case STANDARD:
		ss << *(dynamic_cast<CStandardAcc*>(object));
		break;
	case STUDENT:
		ss << *(dynamic_cast<CStudnetAcc*>(object));
		break;
	case SAVINGS:
		ss << *(dynamic_cast<CSavingsAcc*>(object));
		break;
	}
	return ss.str();
}

IAccount* loadAcc(std::ifstream& f)
{
	accountType type;
	IAccount* buffer;
	f >> type;

	switch (type)
	{
	case BUSINESS:
		buffer = new CBusinessAcc;
		f >> *(dynamic_cast<CBusinessAcc*>(buffer));
		break;
	case STANDARD:
		buffer = new CStandardAcc;
		f >> *(dynamic_cast<CStandardAcc*>(buffer));
		break;
	case STUDENT:
		buffer = new CStudnetAcc;
		f >> *(dynamic_cast<CStudnetAcc*>(buffer));
		break;
	case SAVINGS:
		buffer = new CSavingsAcc;
		f >> *(dynamic_cast<CSavingsAcc*>(buffer));
		break;
	case INVESTITION:
		return NULL;
		break;
	default:
		return NULL;
	}
	return buffer;
}

IAccount::~IAccount(void)
{
}
