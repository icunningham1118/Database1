#include "Table.h"



bool Table::addItem(Item *newItem) {
	if (!keyExists(newItem->getKey())) {
		idTable[newItem->getKey()] = *newItem;
	}
}

bool Table::deleteItem(int key) {
	if (keyExists(key)) {
		idTable.erase(key);
	}
}

bool Table::getItem(int key) {
	idTable.
}

bool Table::keyExists(int key) {
	return idTable.contains(key);
}