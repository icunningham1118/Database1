#include "main.h"


int main() {
	if (!std::filesystem::exists(LOGNAME)) {
		//Log file is created if program is run for the first time. 
		//LOGNAME = "log.txt"
		std::ofstream logCreate{ LOGNAME };
		logCreate << 0;
		logCreate.close();
	}
	//Log file is opened and checked.
	/*********************
	* 0 in log.txt means database needs to be built
	* 1 in log.txt means database should be present
	**********************/
	std::fstream log;
	log.open(LOGNAME, std::ios::in | std::ios::out);
	int logFlag;
	log >> logFlag;

	if (!logFlag) {
		std::cout << "First time user, building database..." << std::endl;
		std::ofstream dBase;
		std::ifstream table;

		const char delim = '|';
		table.open("test.tbl");
		dBase.open("database.json");

		std::string line;
		while (std::getline(table, line)) {
			std::string tline;
			Data tData;
			nlohmann::ordered_json jObject;
			std::stringstream ss(line);

			std::getline(ss, tline, delim);
			tData.key = std::stoi(tline);

			std::getline(ss, tline, delim);
			tData.name = tline;

			std::getline(ss, tline, delim);
			tData.mfgr = tline;

			std::getline(ss, tline, delim);
			tData.brand = tline;

			std::getline(ss, tline, delim);
			tData.type = tline;

			std::getline(ss, tline, delim);
			tData.size = std::stoi(tline);

			std::getline(ss, tline, delim);
			tData.container = tline;

			std::getline(ss, tline, delim);
			tData.price = std::stof(tline);

			std::getline(ss, tline, delim);
			tData.comment = tline;

			jObject = { {"id", tData.key},
				{"name", tData.name},
				{"mfgr", tData.mfgr},
				{"brand", tData.brand},
				{"type", tData.type},
				{"size", tData.size},
				{"container", tData.container},
				{"price", tData.price},
				{"comment", tData.comment}
			};
			dBase << jObject;
		}
			//key, name, mfgr, brand, type, size, container, price, comment
			table.close();
			log.close();
			dBase.close();
	}

}
	
