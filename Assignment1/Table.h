#ifndef TABLE_H
#define TABLE_H

#include <unordered_map>
#include "Item.h"

class Table
{
public:
	bool addItem(int);
	bool deleteItem(int);
	bool getItem(int);
private:
	void hash(int);
	bool keyExists(int);
	std::unordered_map<int, int> idTable;
};

#endif //TABLE_H
