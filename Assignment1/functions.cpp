#include "functions.h"
bool buildDatabase() {
	std::vector<dj::Data> vData;
	parseTable(vData);
	serializeData(vData);
	vData.clear();
	return true;
}
bool parseTable(std::vector<dj::Data> &vData) {
	const char delim = '|';
	std::ifstream inFile;
	inFile.open(PARTTABLE);

	std::string line;

	while (std::getline(inFile, line)) {
		std::string tline;
		dj::Data tData;

		std::stringstream ss(line);

		//key
		std::getline(ss, tline, delim);
		tData.key = std::stoi(tline);

		//name
		std::getline(ss, tline, delim);
		tData.name = tline;

		//manufacturer
		std::getline(ss, tline, delim);
		tData.mfgr = tline;

		//brand
		std::getline(ss, tline, delim);
		tData.brand = tline;

		//type
		std::getline(ss, tline, delim);
		tData.type = tline;

		//size
		std::getline(ss, tline, delim);
		tData.size = std::stoi(tline);

		//container
		std::getline(ss, tline, delim);
		tData.container = tline;

		//price
		std::getline(ss, tline, delim);
		tData.price = std::stof(tline);

		//comment
		std::getline(ss, tline, delim);
		tData.comment = tline;

		vData.push_back(tData);
	}
	return true;
}

bool serializeData(std::vector<dj::Data>& d) {
	std::ofstream dBase(DATABASE);
	json j = d;
	dBase << j;
	return true;
}

void writeLog() {
	std::ofstream log(LOG);
	log << 1;
}

bool readLog() {
	std::ifstream log(LOG);
	int i;
	log >> i;
	return i;
}

