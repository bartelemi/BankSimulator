#include "accounts.h"
#include "TQueue.h"

using namespace std;

template <typename T>
TQueue<T>::TQueue(void)
{
}

template <typename T>
int TQueue<T>::add(T* object)
{
	if(object != NULL)
	{
		list.push_back(object);
		return 0;
	}
	return -1;
}

template <typename T>
int TQueue<T>::search(T& object)
{
	for(int i = 0; i < list.size(); i++)
		if( list[i] == object )
			return i;

	return -1;
}

template <typename T>
int TQueue<T>::remove(T& object)
{
	for(int i = 0; i < list.size(); i++)
		if( list[i] == object )
		{
			list.erase(i);
			return 0;
		}
		return -1;
}

template <typename T>
int TQueue<T>::saveToFile(const string fName, string (*save)(T* object))
{
	ofstream file;

	file.open(fName, ios::out);
	if(file.is_open())
	{
		file.seekp(ios::beg);
		file << this->size() << endl;

		for(unsigned i = 0; i < size(); i++)
			file << save(list[i]) << endl;

		file.close();
		return 0;
	}
	else
		return -1;
}

template <typename T>
int TQueue<T>::loadFromFile(const std::string fName, T* (*load)(std::ifstream& f))
{
	std::ifstream file;
	
	file.open(fName, ios::in);
	if(file.is_open())
	{
		T* buffer;
		unsigned size, count = 0;

		file.seekg(ios::beg);
		file >> size;

		while( !file.eof() && count < size)
		{
			buffer = (*load)(file);
			this->add(buffer);
			++count;
		}
		file.close();
		return count;
	}
	else
		return -1;
}

template <typename T>
T& TQueue<T>::operator[] (unsigned int index) const
{
	if(index >= 0 && index < size() )
		return *list[index];
	else
		return *list[size() -1];
}

template <typename T>
TQueue<T>::~TQueue(void)
{
	for(unsigned i = 0; i < list.size(); i++)
		delete list[i];
}