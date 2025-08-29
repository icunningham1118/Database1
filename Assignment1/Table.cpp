#include "Table.h"



bool Table::addItem(int key) {
	bool added = false;
	if (!keyExists(keyExists(key))) {
		idTable[key] = key;
		added = true;
	}
	return added;
}

bool Table::deleteItem(int key) {
	bool deleted = false;
	if (keyExists(key)) {
		idTable.erase(key);
		deleted = true;
	}
	return deleted;
}

bool Table::getItem(int key) {
	return true;
}

bool Table::keyExists(int key) {
	return idTable.contains(key);
}