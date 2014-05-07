#include "CTransaction.h"


CTransaction::CTransaction(IAccount* f, IAccount* t, double a, transactionType tt)
	: from(f), to(t), amount(a), tType(tt)
{
}

void CTransaction::associateAcc(unsigned long int iban, char dir)
{
	if(dir == 'f' || dir == 'F')
	{

	}
	else if(dir == 't' || dir == 'T')
	{

	}
	else
		return;
}

void CTransaction::info() const
{
	from->accountInfo();
	to->accountInfo();

	std::cout << "Kwota transkacji: " << amount << std::endl;
	std::cout << "typ transakcji: ";

	switch(tType)
	{
	case TRANSFER:
		std::cout << "PRZELEW";
		break;
	case QUICKTRANSFER:
		std::cout << "SZYBKI PRZELEW";
		break;
	case WIRETRANSFER:
		std::cout << "POLECENIE PRZELEWU";
		break;
	case DIRECTDEBIT:
		std::cout << "POLECENIE ZAPLATY";
		break;
	case LOAN:
		std::cout << "RATA PO¯YCZKI";
		break;
	case INTEREST:
		std::cout << "ODSETKI";
		break;
	default:
		std::cout << "BRAK INFORMACJI";
	}
	std::cout << std::endl;
}

std::ostream& operator<< (std::ostream& os, CTransaction& tr)
{
	os << tr.from->getIBAN() << std::endl;
	os << tr.to->getIBAN() << std::endl;
	os << tr.amount << std::endl;
	os << tr.tType << std::endl;

	return os;
}

std::istream& operator>> (std::istream& is, CTransaction& tr)
{
	unsigned long int iban;
	is >> iban;
	tr.associateAcc(iban, 'f');
	is >> iban;
	tr.associateAcc(iban, 't');
	is >> tr.amount;
	is >> tr.tType;

	return is;
}

std::string saveTran(CTransaction* object)
{
	std::stringstream ss;
	ss << (*object);
	return ss.str();
}

CTransaction* loadTran(std::ifstream& f)
{
	CTransaction* buffer = new CTransaction;
	f >> (*buffer);
	return buffer;
}

CTransaction::~CTransaction(void)
{
}
