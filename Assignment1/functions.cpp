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

void logCheck() {
	std::ifstream log(LOG);
	if (!log.is_open()) {
		std::ofstream log(LOG);
		log << 0;
	}
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

std::string getRandomStr() {
	/*********************************************
		Generates a random string of lowercase alphabetical characters.

		@param None.

		@return randomString : A randomly generated string.

		@note Generates a string of random length between 5 and 10 characters.
				Each character in the string is a random lowercase alphabetical character.

		@exception None.
	*********************************************/
	int length = rand() % 6 + 5; // Random number between 5 and 10

	// Generate the random string
	std::string randomString;
	for (int i = 0; i < length; ++i) {
		char randomChar = 'a' + rand() % 26; // Random lowercase alphabetical character
		randomString += randomChar;
	}

	return randomString;
}

float getRandomFloat() {
	return (static_cast <float>(rand()) / (static_cast <float>(RAND_MAX / 50)));
}

dj::Data fillTestData(int elementsInJ,int max) {
	dj::Data tData;
	tData.key = elementsInJ + (rand() % (max - elementsInJ + 1));
	tData.name = getRandomStr();
	tData.mfgr = getRandomStr();
	tData.brand = getRandomStr();
	tData.type = getRandomStr();
	tData.size = elementsInJ + (rand() % (max - elementsInJ + 1));
	tData.container = getRandomStr();
	tData.price = getRandomFloat();
	tData.comment = getRandomStr();
	return tData;
}