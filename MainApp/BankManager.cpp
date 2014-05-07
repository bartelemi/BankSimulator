#include "BankManager.h"


BankManager& BankManager::getInstance()
{
	static BankManager instance;
	return instance;
}

void BankManager::initialize(std::string fName)
{
	fileNameprefix = fName;
	IBANs.loadFromFile(fileNameprefix, &loadInt);
	accounts.loadFromFile(fileNameprefix, &loadAcc);
	pendingTransactions.loadFromFile(fileNameprefix, &loadTran);
	completedTransactions.loadFromFile(fileNameprefix, &loadTran);
}

void BankManager::showAcc()
{
	std::cout << accounts;
}


BankManager::~BankManager(void)
{
	IBANs.saveToFile(fileNameprefix, &saveInt);
	accounts.saveToFile(fileNameprefix, &saveAcc);
	pendingTransactions.saveToFile(fileNameprefix, &saveTran);
	completedTransactions.saveToFile(fileNameprefix, &saveTran);
}