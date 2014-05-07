#pragma once

enum currency
{
	PLN,
	GBP,
	EUR
};

enum countries
{
	POLAND,
	GB,
	GERMANY
};

enum transactionType
{
	TRANSFER,
	QUICKTRANSFER,
	WIRETRANSFER,
	DIRECTDEBIT,
	LOAN,
	INTEREST
};

enum accountType
{
	BUSINESS,
	STANDARD,
	STUDENT,
	SAVINGS,
	INVESTITION
};

template<typename T>
typename std::enable_if<std::is_enum<T>::value, std::istream&>::type
operator >>(std::istream &is, T& enumVar)
{
  int intVal;
  is >> intVal;
  enumVar = static_cast<T>(intVal); // note the explicit cast to make it legal
  return is;
}

