#include "IBAN.h"

using namespace priv;

unsigned long int IBANgenerator(const unsigned short int BankID)
{
	unsigned int value;
	unsigned long int newIBAN;
	newIBAN = static_cast<unsigned long int>(BankID * MAX_ACC_COUNT);

	value = 10 + (rand() % 89);
	newIBAN += (last + value);
	last += value;

	return newIBAN;
}

unsigned long int* loadInt(std::ifstream& f)
{
	unsigned long int* iban = new unsigned long int;
	f >> *iban;
	return iban;
}

std::string saveInt(unsigned long int* object)
{
	char buffer[11];
	_i64toa_s(*object, buffer, 11, 10);
	return buffer;
}