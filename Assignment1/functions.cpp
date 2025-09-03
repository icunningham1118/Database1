#include "functions.h"
void initialBuildDatabase() {
	/*********************************************
		GBuilds the database

		@param None.

		@return none.

		@note Starts with a vector of Data which will be filled with parsed information from the part.tbl file
			  First the data is parsed with the parseTable function and then goes to the serializeData function
			  to be put into a json file. Redundant vector clear call.

		@exception None.
	*********************************************/
	std::vector<dj::Data> vData;
	parseTable(vData);
	serializeData(vData);
	vData.clear();
}
void parseTable(std::vector<dj::Data> &vData) {
	/*********************************************
		Gets data from a specific delimited .tbl file and fills a dj::Data struct instance that is pushed
		into the vData vector

		@param vData by reference.

		@return none.

		@note Generates a string of random length between 5 and 10 characters.
				Each character in the string is a random lowercase alphabetical character.

		@exception None.
	*********************************************/
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
}

void serializeData(std::vector<dj::Data>& d) {
	/*********************************************
		Creates or overwrites a database.json file to insert serialized data.

		@param dj::Data vector by reference.

		@return none.

		@note Since nlohmann json objects views vector objects as a JSON array, we can
			  set our vector as a JSON object and write it to the database.json file.

		@exception None.
	*********************************************/
	std::ofstream dBase(DATABASE);
	json j = d;
	dBase << j;
}

void logCheck() {
	/*********************************************
		Checks if there is a log to read from and if there is none it inserts the value 0.

		@param None.

		@return None

		@exception None.
	*********************************************/
	std::ifstream log(LOG);
	if (!log.is_open()) {
		std::ofstream log(LOG);
		log << 0;
	}
}
void writeLog() {
	/*********************************************
		Writes 1 to log.txt

		@param None.

		@return None.

		@exception None.
	*********************************************/
	std::ofstream log(LOG);
	log << 1;
}

bool readLog() {
	/*********************************************
		Reads log

		@param None.

		@return int i for data in the file.

		@exception None.
	*********************************************/
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
	/*********************************************
		Generates a random float

		@param None.

		@return float : A randomly generated float.

		@note Float will be between header file defined RAND_MAX and 50.

		@exception None.
	*********************************************/
	return (static_cast <float>(rand()) / (static_cast <float>(RAND_MAX / 50)));
}

dj::Data fillTestData(int elementsInJ,int max) {
	/*********************************************
		Generates random data to be used for testing.

		@param int elementsInJ, int max

		@return dj::Data : filled Data variable

		@exception None.
	*********************************************/
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

void testSuite() {
	std::cout << "Press any key to begin" << std::endl;
	std::getchar();
	std::cout << "=======================================" << std::endl;
	std::cout << "Beginning search tests..." << std::endl;
	testSearchKey();
	testSearchName();
	testSearchBrand();
	testSearchType();
}
void testSearchKey() {

}

void testSearchName() {

}

void testSearchBrand() {

}

void testSearchType() {

}