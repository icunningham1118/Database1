#include "main.h"


int main() {
	std::cout << "Hello" << std::endl;
	std::ifstream table;
	const char delim = '|';
	table.open("test.tbl");
	int catergories = 9;
	int key = 0, size = 0;
	float price = 0.0;
	std::string name, container, brand, mfgr, comment, type;
	std::string line, tline;
	Data d[2];


	int i = 0;
	while (std::getline(table, line)) {


		std::stringstream ss(line);

		std::getline(ss, tline, delim);
		d[i].key = std::stoi(tline);

		std::getline(ss, tline, delim);
		d[i].name = tline;

		std::getline(ss, tline, delim);
		d[i].mfgr = tline;

		std::getline(ss, tline, delim);
		d[i].brand = tline;

		std::getline(ss, tline, delim);
		d[i].type = tline;

		std::getline(ss, tline, delim);
		d[i].size = std::stoi(tline);

		std::getline(ss, tline, delim);
		d[i].container = tline;

		std::getline(ss, tline, delim);
		d[i].price = std::stof(tline);

		std::getline(ss, tline, delim);
		d[i].comment = tline;
		i++;

		//key, name, mfgr, brand, type, size, container, price, comment
		Item* item = new Item(d[i].key, d[i].name, d[i].mfgr, d[i].brand, d[i].type, d[i].size, d[i].container, d[i].price, d[i].comment);

	}
	for (int j = 0; j < 2; j++) {
		std::cout << "key: " << d[j].key << std::endl;
		std::cout << "name: " << d[j].name << std::endl;
		std::cout << "mfgr: " << d[j].mfgr << std::endl;
		std::cout << "brand: " << d[j].brand << std::endl;
		std::cout << "type: " << d[j].type << std::endl;
		std::cout << "size: " << d[j].size << std::endl;
		std::cout << "container: " << d[j].container << std::endl;
		std::cout << "price: " << d[j].price << std::endl;
		std::cout << "comment: " << d[j].comment << std::endl;
	}


	table.close();

	

}
