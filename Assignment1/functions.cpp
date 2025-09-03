#include "functions.h"
void initialBuildDatabase() {
	/*********************************************
		@Builds the database

		@param None.

		@return none.

		@note Starts with a vector of Data which will be filled with parsed information from the part.tbl file
			  First the data is parsed with the parseTable function and then goes to the serializeData function
			  to be put into a json file. Redundant vector clear call.

		@exception None.
	*********************************************/
	std::vector<dj::Data> vData;
	parseTable(vData);
	saveDatabase(vData);
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

void saveDatabase(std::vector<dj::Data>& d) {
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
	dBase << j.dump(4);
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
std::vector<dj::Data> loadDatabase() {
	std::ifstream inFile(DATABASE);
	json j;
	inFile >> j;
	inFile.close();

	std::vector<dj::Data> dataVec;
	for (auto& e : j) {
		dataVec.push_back(e.get<dj::Data>());
	}
	return dataVec;
}
void insertPart(std::vector<dj::Data>& dataVec) {
	dj::Data p;
	std::cout << "Enter PARTKEY: ";
	std::cin >> p.key;
	std::cin.ignore();
	std::cout << "Enter NAME: ";
	std::getline(std::cin, p.name);
	std::cout << "Enter MFGR: ";
	std::getline(std::cin, p.mfgr);
	std::cout << "Enter BRAND: ";
	std::getline(std::cin, p.brand);
	std::cout << "Enter TYPE: ";
	std::getline(std::cin, p.type);
	std::cout << "Enter SIZE: ";
	std::cin >> p.size;
	std::cin.ignore();
	std::cout << "Enter CONTAINER: ";
	std::getline(std::cin, p.container);
	std::cout << "Enter PRICE: ";
	std::cin >> p.price;
	std::cin.ignore();
	std::cout << "Enter COMMENT: ";
	std::getline(std::cin, p.comment);

	// Check uniqueness
	for (auto& e : dataVec) {
		if (e.key == p.key || e.name == p.name) {
			std::cout << "Part with same KEY or NAME already exists. Insert aborted.\n";
			return;
		}
	}

	dataVec.push_back(p);
	std::cout << "Part inserted successfully!\n";
}

// Search parts
void searchParts(std::vector<dj::Data> &dataVec) {
	int choice;
	std::cout << "Search by: 1) PARTKEY 2) NAME 3) BRAND 4) TYPE\nChoice: ";
	std::cin >> choice;
	std::cin.ignore();

	// Get search query
	std::string query;
	int queryInt;
	bool found = false;

	switch (choice) {
	case 1:
		std::cout << "Enter PARTKEY: ";
		std::cin >> queryInt;
		for (auto& e : dataVec) {
			if (e.key == queryInt) {
				std::cout << e.key << " | " << e.name << " | " << e.brand << " | " << e.type << std::endl;
				found = true;
			}
		}
		break;
	case 2:
		std::cout << "Enter NAME: ";
		std::getline(std::cin, query);
		for (auto& e : dataVec) {
			if (e.name == query) {
				std::cout << e.key << " | " << e.name << " | " << e.brand << " | " << e.type << std::endl;
				found = true;
			}
		}
		break;
	case 3:
		std::cout << "Enter BRAND: ";
		std::getline(std::cin, query);
		for (auto& e : dataVec) {
			if (e.brand == query) {
				std::cout << e.key << " | " << e.name << " | " << e.brand << " | " << e.type << std::endl;
				found = true;
			}
		}
		break;
	case 4:
		std::cout << "Enter TYPE: ";
		std::getline(std::cin, query);
		for (auto& e : dataVec) {
			if (e.type == query) {
				std::cout << e.key << " | " << e.name << " | " << e.brand << " | " << e.type << std::endl;
				found = true;
			}
		}
		break;
	default:
		std::cout << "Invalid choice.\n";
	}
	if (!found) std::cout << "No results found.\n";
}
void updatePart(std::vector<dj::Data>& dataVec) {
	int key;
	std::cout << "Enter PARTKEY of the item to update: ";
	std::cin >> key;
	std::cin.ignore();

	for (auto& e : dataVec) {
		if (e.key == key) {
			std::string input;
			std::cout << "Updating record (press ENTER to keep current value).\n";

			std::cout << "NAME (" << e.name << "): ";
			std::getline(std::cin, input);
			if (!input.empty()) e.name = input;

			std::cout << "MFGR (" << e.mfgr << "): ";
			std::getline(std::cin, input);
			if (!input.empty()) e.mfgr = input;

			std::cout << "BRAND (" << e.brand << "): ";
			std::getline(std::cin, input);
			if (!input.empty()) e.brand = input;

			std::cout << "TYPE (" << e.type << "): ";
			std::getline(std::cin, input);
			if (!input.empty()) e.type = input;

			std::cout << "SIZE (" << e.size << "): ";
			std::getline(std::cin, input);
			if (!input.empty()) e.size = stoi(input);

			std::cout << "CONTAINER (" << e.container << "): ";
			std::getline(std::cin, input);
			if (!input.empty()) e.container = input;

			std::cout << "PRICE (" << e.price << "): ";
			std::getline(std::cin, input);
			if (!input.empty()) e.price = stof(input);

			std::cout << "COMMENT (" << e.comment << "): ";
			std::getline(std::cin, input);
			if (!input.empty()) e.comment = input;

			std::cout << "Record updated.\n";
			return;
		}
	}
	std::cout << "PARTKEY not found.\n";
}

// Delete a part
void deletePart(std::vector<dj::Data>& dataVec) {
	int key;
	std::cout << "Enter PARTKEY of the item to delete: ";
	std::cin >> key;

	auto it = remove_if(dataVec.begin(), dataVec.end(),
		[key](const dj::Data& p) { return p.key == key; });
	if (it != dataVec.end()) {
		dataVec.erase(it, dataVec.end());
		std::cout << "Record deleted.\n";
	}
	else {
		std::cout << "PARTKEY not found.\n";
	}
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
	/*********************************************
		Contains all the testing for searching and alteration.

		@param None.

		@return void.

		@note Creates all of the necessary variables that will all go out of scope
			  after testing is complete so it will not mess with the actual database.
			  Does require the database to be available.

		@exception None.
	*********************************************/
	std::ifstream inFile("database.json");
	json j;
	inFile >> j;
	inFile.close();
	size_t elementsInJ = size(j);
	std::vector<dj::Data> testData;
	for (auto& e : j) {
		testData.push_back(e.template get<dj::Data>());
	}
	std::cout << "\n=======================================\n";
	std::cout << "Beginning search tests...\n";
	std::cout << "\n=======================================\n" << std::endl;
	std::cout << "Search by key...\n" << std::endl;
	testSearchKey(j, elementsInJ);
	std::cout << "Search by name...\n" << std::endl;
	testSearchName(j, testData, elementsInJ);
	std::cout << "Search by brand...\n" << std::endl;
	testSearchBrand(j, testData, elementsInJ);
	std::cout << "Search by type...\n" << std::endl;
	testSearchType(j, testData, elementsInJ);
	testData.clear();
	std::cout << "\n=======================================\n";
	std::cout << "Beginning alteration tests...\n";
	std::cout << "\n=======================================\n" << std::endl;
	std::cout << "\nAdding a part...\n" << std::endl;
	testAdd(j, testData, elementsInJ);
	std::cout << "\nUpdating a part...\n" << std::endl;
	dj::Data tData = testUpdate(j, elementsInJ);
	std::cout << "\nDeleting a part...\n" << std::endl;
	testDelete(j, elementsInJ, tData);
}

void testSearchKey(json &j, size_t &elementsInJ) {
	/*********************************************
		Tests search by key functionality

		@param json &j size_t elementsInJ

		@return void

		@Note Iterates through the json object and checks for a specific key.
			  Cuts loop short if key is found.
		@exception None.
	*********************************************/
	dj::Data d1;
	size_t key = (rand() % elementsInJ) + 1;

	std::cout << "searching for key: " << key << std::endl;
	for (size_t i = 0; i < elementsInJ; i++) {
		if (j[i]["key"] == key) {
			d1 = j[i].template get<dj::Data>();
			i = elementsInJ;
		}
	}
	std::cout << "\n==================================================================\n";
	std::cout << d1.key << " " << d1.name << " " << d1.brand << " " << d1.type << "\n";
	std::cout << "\n==================================================================\n" << std::endl;
	std::cout << "\nsearching for key: " << MAX << std::endl;

	for (size_t i = 0; i < elementsInJ; i++) {
		if (j[i]["key"] == MAX) {
			d1 = j[i].template get<dj::Data>();
			i = elementsInJ;
		}
	}
	if (d1.key != MAX) {
		std::cout << "\nNo part with key: " << MAX << " found.\n" << std::endl;
	}
}

void testSearchName(json &j, std::vector<dj::Data> &testData, size_t &elementsInJ) {
	/*********************************************
		Tests search by name functionality

		@param json &j size_t elementsInJ

		@return void

		@Note Iterates through the json object and checks for a specific name.
			  Cuts loop short if name is found.

		@exception None.
	*********************************************/
	dj::Data d1;
	size_t key = (rand() % elementsInJ);
	std::cout << "searching for name: " << testData[key].name << std::endl;
	std::string testString = testData[key].name;
	for (size_t i = 0; i < elementsInJ; i++) {
		if (j[i]["name"] == testString) {
			d1 = j[i].template get<dj::Data>();
			i = elementsInJ;
		}
	}
	std::cout << "\n==================================================================\n";
	std::cout << d1.key << " " << d1.name << " " << d1.brand << " " << d1.type << "\n";
	std::cout << "\n==================================================================\n" << std::endl;

	testString = "TESTFORFAILCHECK";
	std::cout << "\nsearching for name: " << testString << std::endl;
	
	for (size_t i = 0; i < elementsInJ; i++) {
		if (j[i]["name"] == testString) {
			d1 = j[i].template get<dj::Data>();
			i = elementsInJ;
		}
	}
	if (d1.name != testString) {
		std::cout << "\nNo part with name: " << testString << " found.\n" << std::endl;
	}
}

void testSearchBrand(json &j, std::vector<dj::Data> &testData, size_t &elementsInJ) {
	/*********************************************
		Tests search by brand functionality

		@param json &j size_t elementsInJ

		@return void

		@Note Iterates through the json object and checks for parts from a specific brand.
			  Keeps a counter of each part of that brand and collects the parts in a vector.
		@exception None.
	*********************************************/
	size_t key = (rand() % elementsInJ);
	std::cout << "searching for brands: " << testData[key].brand << std::endl;
	std::string testString = testData[key].brand;
	int c = 0;
	std::vector<dj::Data> multiFind;
	for (int i = 0; i < elementsInJ; i++) {
		if (j[i]["brand"] == testString) {
			multiFind.push_back(j[i].template get<dj::Data>());
			c++;
		}
	}
	std::cout << "\n==================================================================\n";
	std::cout << "Found " << c << " different items from " << testString << " brand.\n";
	for (auto& e : multiFind) {
		std::cout << e.key << " " << e.name << " " << e.brand << " " << e.type << "\n";
	}
	std::cout << "\n==================================================================\n" << std::endl;
	testString = "TESTFORFAILCHECK";
	std::cout << "\nsearching for brands: " << testString << std::endl;
	multiFind.clear();
	c = 0;
	for (int i = 0; i < elementsInJ; i++) {
		if (j[i]["brand"] == testString) {
			multiFind.push_back(j[i].template get<dj::Data>());
			c++;
		}
	}
	if (c == 0) {
		std::cout << "\nNo parts from brand: " << testString << " found.\n" << std::endl;
	}
}

void testSearchType(json &j, std::vector<dj::Data> &testData, size_t &elementsInJ) {
	/*********************************************
		Tests search by type functionality

		@param json &j size_t elementsInJ

		@return void

		@Note Iterates through the json object and checks for parts of a specific type.
			  Keeps a counter of each part of that type and collects the parts in a vector.
		@exception None.
	*********************************************/
	int c = 0;
	size_t key = (rand() % elementsInJ);
	std::vector<dj::Data> multiFind;
	std::string testString;

	std::cout << "searching for types: " << testData[key].type << std::endl;
	testString = testData[key].type;
	for (int i = 0; i < elementsInJ; i++) {
		if (j[i]["type"] == testString) {
			multiFind.push_back(j[i].template get<dj::Data>());
			c++;
		}
	}
	
	std::cout << "\n==================================================================\n";
	std::cout << "Found " << c << " different items of " << testString << " type.\n";

	for (auto& e : multiFind) {
		std::cout << e.key << " " << e.name << " " << e.brand << " " << e.type << "\n";
	}
	std::cout << "\n==================================================================\n";

	testString = "TESTFORFAILCHECK";
	std::cout << "\nsearching for type: " << testString << std::endl;
	multiFind.clear();
	c = 0;
	for (int i = 0; i < elementsInJ; i++) {
		if (j[i]["type"] == testString) {
			multiFind.push_back(j[i].template get<dj::Data>());
			c++;
		}
	}
	if (c == 0) {
		std::cout << "\nNo parts of type: " << testString << " found.\n" << std::endl;
	}
}

void testAdd(json& j, std::vector<dj::Data> &testData, size_t& elementsInJ) {
	/*********************************************
		Tests add part functionality

		@param json &j size_t elementsInJ

		@return void

		@Note Iterates through the json object and checks to see if key already exists.
			  If it does then it will abort the addition of the part. Else it will add the part.
		@exception None.
	*********************************************/
	for (int i = 0; i < 10; i++) {
		dj::Data tData = fillTestData(elementsInJ, MAX);
		testData.push_back(tData);
		testData.push_back(tData);
	}
	int found = 0;
	int added = 0;
	for (int i = 0; i < std::size(testData); i++) {
		for (int q = 0; q < elementsInJ; q++) {
			if (testData[i] == j[q].template get<dj::Data>()) {
				q = elementsInJ;
				found++;
				std::cout << "Part add abort. New part needs unique name and key" << std::endl;
			}
			else if (j[q] == j.back() && testData[i] != j[q].template get<dj::Data>()) {
				j.push_back(testData[i]);
				elementsInJ++;
				q = elementsInJ;
				added++;
				std::cout << "Part added" << std::endl;
			}
		}
	}
}

dj::Data testUpdate(json& j, size_t& elementsInJ) {
	/*********************************************
		Tests update part functionality

		@param json &j size_t elementsInJ

		@return Data

		@Note Iterates through the json object and checks to see if key already exists.
			  If it does then it will update the part. This test changes every attribute of part.
		@exception None.
	*********************************************/
	dj::Data tData = fillTestData(elementsInJ, MAX);
	int key = (rand() % elementsInJ) + 1;
	tData.key = key;
	std::cout << "================================\n";
	std::cout << "Part to be added: key-" << tData.key << " name- " << tData.name << " mfgr- " << tData.mfgr << " brand- " << tData.brand << " type- ";
	std::cout << tData.type << " size- " << tData.size << " container- " << tData.container << " price- " << tData.price << " comment- " << tData.comment << "\n";
	std::cout << "================================" << std::endl;
	for (int i = 0; i < elementsInJ; i++) {
		if (j[i]["key"] == tData.key) {
			std::cout << "================================\n";
			std::cout << "JSON Part: " << j[i] << " before.\n";
			std::cout << "================================" << std::endl;
			j[i] = tData;
			std::cout << "================================\n";
			std::cout << "JSON Part: " << j[i] << " after.\n";
			std::cout << "================================" << std::endl;
			i = elementsInJ;
		}
	}
	return tData;
}

void testDelete(json& j, size_t& elementsInJ, dj::Data tData) {
	/*********************************************
		Tests delete part functionality

		@param json &j size_t elementsInJ

		@return void

		@Note Iterates through the json object and checks to see if key exists.
			  If it does not then no deletion will occur. Else it will delete the part.
		@exception None.
	*********************************************/
	for (int i = 0; i < elementsInJ; i++) {
		if (j[i]["key"] == tData.key) {
			std::cout << "JSON Part: " << j[i] << " before deletion.\n";
			j.erase(i);
			elementsInJ--;
			std::cout << "Checking for deletion...\n";
			bool foundIt = false;
			for (size_t i = 0; i < elementsInJ; i++) {
				if (j[i]["key"] == tData.key) {
					tData = j[i].template get<dj::Data>();
					i = elementsInJ;
					foundIt = true;
				}
			}
			if (foundIt) {
				std::cout << "Deletion failed." << std::endl;
			}
			else {
				std::cout << "Successfully deleted" << std::endl;
			}
		}
	}
}