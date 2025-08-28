#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item
{
public:
	/********************
   Constructor/Destructor
   *********************/
	Item();
	//key, name, mfgr, brand, type, size, container, price, comment
	Item(int, std::string, std::string, std::string, std::string, int, std::string, float, std::string);

	/********************
	Setters
	*********************/
	bool setKey(int);
	bool setSize(int);
	bool setPrice(float);
	bool setName(std::string);
	bool setMfgr(std::string);
	bool setBrand(std::string);
	bool setType(std::string);
	bool setContainer(std::string);
	bool setComment(std::string);
	/********************
	Getters
	*********************/
	int getKey();
	int getSize();
	float getPrice();
	std::string getName();
	std::string getMfgr();
	std::string getBrand();
	std::string getType();
	std::string getContainer();
	std::string getComment();
private:
	int key = 0;
	int size = 0;
	float price = 0;

	std::string name = "";
	std::string mfgr = "";
	std::string brand = "";
	std::string type = "";
	std::string container = "";
	std::string comment = "";
	
};

#endif /*ITEM_H*/