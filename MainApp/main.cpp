#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "BankManager.h"
#include "IAccount.h"
#include "IBAN.h"

using namespace std;

IAccount* fabryka()
{
	unsigned randomize;
	randomize = rand() % 3;

	switch (randomize)
	{
	case 0:

		return new CBusinessAcc(5.0, IBANgenerator());
		break;
	case 1:

		return new CStandardAcc(4.5, IBANgenerator());
		break;
	case 2:

		return new CStudnetAcc(3.0, IBANgenerator());
		break;
	default:
		return NULL;
	}
}

int main(int argc, void** argv)
{
	{
		TQueue<IAccount> kolejka, kolejka2;

		for(unsigned i = 0; i < 5; i++)
		{
			kolejka.add(fabryka());
		}
		
		cout << kolejka;
		kolejka.saveToFile("output.txt", &saveAcc);

		cout << "**************************************************************************" << endl;

		BankManager::getInstance().initialize("output.txt");
		BankManager::getInstance().showAcc();
	} _CrtDumpMemoryLeaks();
	
	return 0;
}


/*
IDEAS AND TODOs
 -wymy�li� co� z przeci��eniem operatora istream >> :
  jak pobra� numer iban konta oszcz�dno�ciowego i przypisa� do wcze�niejszego konta?
 
 -IAccountManagement:
 zdefiniowa�: associateSavingsAcc()

 -Ctransaction
 zdefiniowa�: associateAcc()

 Do TQueue potrzeba:
 -konstruktor kopiuj�cy ??
 -przeci��one operatory >> i <<

*/