
#ifndef DATA_H
#define DATA_H

#include <string>
#include "json.hpp"

using json = nlohmann::json;
namespace dj {
	struct Data {
		int key = 0, size = 0;
		float price = 0.0;
		std::string name, container, brand, mfgr, comment, type;
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, key, name, mfgr, brand, type, size, container, price, comment);
	};

	//void to_json(json&, Data&);
	//void from_json(const json&, Data&);
} //namespace dj
#endif //DATA_H