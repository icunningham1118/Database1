#ifndef TABLE_H
#define TABLE_H

#include <unordered_map>
#include "Item.h"

class Table
{
public:
	bool addItem(Item*);
	bool deleteItem(int);
	bool getItem(int);
private:
	bool keyExists(int);
	std::unordered_map<int, Item> idTable;
};

#endif //TABLE_H
