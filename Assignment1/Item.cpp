#include "Item.h"


Item::Item() {
	key = 0;
	name = "";
	mfgr = "";
	brand = "";
	type = "";
	size = 0;
	container = "";
	price = 0.0;
	comment = "";
}

//key, name, mfgr, brand, type, size, container, price, comment
Item::Item(int newKey, std::string newName, std::string newMfgr, std::string newBrand, std::string newType, int newSize, std::string newContainer, float newPrice, std::string newComment) {
	setKey(newKey);
	setName(newName);
	setMfgr(newMfgr);
	setBrand(newBrand);
	setType(newType);
	setSize(newSize);
	setContainer(newContainer);
	setPrice(newPrice);
	setComment(newComment);
}
int Item::getKey() {
	return key;
}

int Item::getSize() {
	return size;
}

float Item::getPrice() {
	return price;
}

std::string Item::getName() {
	return name;
}

std::string Item::getMfgr() {
	return mfgr;
}

std::string Item::getBrand() {
	return brand;
}

std::string Item::getType() {
	return type;
}

std::string Item::getContainer() {
	return container;
}

std::string Item::getComment() {
	return comment;
}

bool Item::setKey(int newKey) {
	bool set = false;
	if (newKey > 0) {
		key = newKey;
		set = true;
	}
	return set;
}

bool Item::setPrice(float newPrice) {
	bool set = false;
	if (newPrice > 0) {
		price = newPrice;
		set = true;
	}
	return set;
}

bool Item::setSize(int newSize) {
	bool set = false;
	if (newSize > 0) {
		size = newSize;
		set = true;
	}
	return set;
}

bool Item::setBrand(std::string newBrand) {
	bool set = false;
	if (newBrand != "") {
		brand = newBrand;
		set = true;
	}
	return set;
}

bool Item::setName(std::string newName) {
	bool set = false;
	if (newName != "") {
		name = newName;
		set = true;
	}
	return set;
}

bool Item::setMfgr(std::string newMfgr) {
	bool set = false;
	if (newMfgr != "") {
		mfgr = newMfgr;
		set = true;
	}
	return set;
}

bool Item::setType(std::string newType) {
	bool set = false;
	if (newType != "") {
		type = newType;
		set = true;
	}
	return set;
}

bool Item::setContainer(std::string newContainer) {
	bool set = false;
	if (newContainer != "") {
		container = newContainer;
		set = true;
	}
	return set;
}

bool Item::setComment(std::string newComment) {
	bool set = false;
	if (newComment != "") {
		comment = newComment;
		set = true;
	}
	return set;
}
