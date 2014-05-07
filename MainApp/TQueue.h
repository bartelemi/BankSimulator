#pragma once

#include <vector>
#include <fstream>

template <typename T>
class TQueue
{
private:
	std::vector<T*> list;

public:
	TQueue(void); 

	int add(T* object);
	int search(T& object);
	int remove(T& object);

	inline unsigned int size() const { return list.size(); }
	int saveToFile(const std::string fName, std::string (*save)(T* object));
	int loadFromFile(const std::string fName, T* (*load)(std::ifstream& f));

	T& operator[] (unsigned int index) const;

	friend std::ostream& operator<< (std::ostream& os, class TQueue<T> const& t)
	{
		for(unsigned i = 0; i < t.size(); i++)
		{
			os << t[i] << std::endl;
		}
		return os;
	}

	//friend std::istream& operator>> (std::istream& is, TQueue<T>& t)
	//{
	//	unsigned int size;
	//	is >> size;
	//	for(unsigned i = 0; i < size; i++)
	//	{
	//		T tmp;
	//		is >> tmp;
	//		t.add(&tmp);
	//	}
	//	return is;
	//}

	virtual ~TQueue(void);
};