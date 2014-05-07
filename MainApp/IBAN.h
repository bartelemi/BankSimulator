#pragma once

#include <string>
#include <fstream>
#include <stdlib.h>

namespace priv
{
	//zmienna przechowujaca ostatni numer iban
	//dla zapewnienia unikatowych numerow, do ostatniego wygenerowanego IBAN
	//bedziemy dodawac jakas losowa wartosc
	static unsigned int last = 0;

	const unsigned short int BANKID = 1337;
	const unsigned int MAX_ACC_COUNT = 1000000;
}	

unsigned long int IBANgenerator(const unsigned short int BankID = priv::BANKID);

unsigned long int* loadInt(std::ifstream& f);
std::string saveInt(unsigned long int* object);

		


