
#ifndef DATA_H
#define DATA_H

#include <string>

struct Data {
	int key = 0, size = 0;
	float price = 0.0;
	std::string name, container, brand, mfgr, comment, type;
	std::string line;
};
#endif //DATA_H