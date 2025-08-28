#include "main.h"


int main() {
	std::cout << "Hello" << std::endl;
	std::ifstream table;
	const char delim = '|';
	table.open("test.tbl");

	int key = 0, size = 0;
	float price = 0.0;
	std::string name, container, brand, mfgr, comment, type;
	std::string line, tline;
	std::queue<Data> dataQ;
	Table table;
	Data d;

	while (std::getline(table, line)) {


		std::stringstream ss(line);
		
		std::getline(ss, tline, delim);
		d.key = std::stoi(tline);

		std::getline(ss, tline, delim);
		d.name = tline;

		std::getline(ss, tline, delim);
		d.mfgr = tline;

		std::getline(ss, tline, delim);
		d.brand = tline;

		std::getline(ss, tline, delim);
		d.type = tline;

		std::getline(ss, tline, delim);
		d.size = std::stoi(tline);

		std::getline(ss, tline, delim);
		d.container = tline;

		std::getline(ss, tline, delim);
		d.price = std::stof(tline);

		std::getline(ss, tline, delim);
		d.comment = tline;

		//key, name, mfgr, brand, type, size, container, price, comment
		dataQ.push(d);

	}
	table.close();

	

}
