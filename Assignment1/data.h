
#ifndef DATA_H
#define DATA_H

#include <string>
#include "json.hpp"

using json = nlohmann::json;
namespace dj {
	struct Data {
		Data();
		Data(int, std::string, std::string, std::string, std::string, int, std::string, float, std::string);
		int key = 0, size = 0;
		float price = 0.0;
		std::string name, container, brand, mfgr, comment, type;
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(Data, key, name, mfgr, brand, type, size, container, price, comment);
	};
	bool operator==(const Data&, const Data&);
	bool operator!=(const Data&, const Data&);

} //namespace dj
#endif //DATA_H