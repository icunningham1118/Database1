/**********************************
Right now we have the serialization in a good place,
still need to test it with the actual part.tbl file.
Need functions to reduce clutter and to compartmentalize
our processes.
Biggest thing is being able to pull the things back out
of the file.
***********************************/
#include "main.h"

int main() {
	srand(time(NULL));
	logCheck();
	//Log file is opened and checked.
	/*********************
	* 0 in log.txt means database needs to be built
	* 1 in log.txt means database should be present
	**********************/
	if (!readLog()) {
		std::cout << "First time user, building database..." << std::endl;

		//Builds database
		if (buildDatabase()) {
			std::cout << "Database has been built!" << std::endl;
		}

		//Updates log to 1
		writeLog();
	}
	else {
		//Launching program after 1st build will display this message
		std::cout << "Welcome back!" << std::endl;
	}

	//Search
	std::ifstream inFile("database.json");
	json j;
	inFile >> j;
	inFile.close();

	size_t elementsInJ = size(j);
	dj::Data d1;
	size_t key = (rand() % elementsInJ) + 1;

	// -->By key [DONE]
	std::cout << "searching for key: " << key << std::endl;
	for (size_t i = 0; i < elementsInJ; i++) {
		if (j[i]["key"] == key) {
			d1 = j[i].template get<dj::Data>();
			i = elementsInJ;
		}
	}
	std::cout << d1.key << " " << d1.name << " " << d1.brand << " " << d1.type << std::endl;
		
	std::vector<dj::Data> testData;
	for (auto& e : j) {
		testData.push_back(e.template get<dj::Data>());
	}
	// -->By name [DONE]
	key = (rand() % elementsInJ);
	std::cout << "searching for name: " << testData[key].name << std::endl;
	std::string testString = testData[key].name;
	for (size_t i = 0; i < elementsInJ; i++) {
		if (j[i]["name"] == testString) {
			d1 = j[i].template get<dj::Data>();
			i = elementsInJ;
		}
	}
	std::cout << d1.key << " " << d1.name << " " << d1.brand << " " << d1.type << std::endl;

	// -->By brand [DONE]
	key = (rand() % elementsInJ);
	std::cout << "searching for brands: " << testData[key].brand << std::endl;
	testString = testData[key].brand;
	int c = 0;
	std::vector<dj::Data> multiFind;
	for (int i = 0; i < elementsInJ; i++) {
		if (j[i]["brand"] == testString) {
			multiFind.push_back(j[i].template get<dj::Data>());
			c++;
		}
	}
	std::cout << "Found " << c << " different items from " << testString << " brand.\n";
	for (auto& e : multiFind) {
		std::cout << e.key << " " << e.name << " " << e.brand << " " << e.type << std::endl;
	}
	multiFind.clear();

	// -->By type [DONE]
	key = (rand() % elementsInJ);
	std::cout << "searching for types: " << testData[key].type << std::endl;
	testString = testData[key].type;

	c = 0;

	for (int i = 0; i < elementsInJ; i++) {
		if (j[i]["type"] == testString) {
			multiFind.push_back(j[i].template get<dj::Data>());
			c++;
		}
	}
	std::cout << "Found " << c << " different items from " << testString << "type.\n";
	for (auto& e : multiFind) {
		std::cout << e.key << " " << e.name << " " << e.brand << " " << e.type << "\n";
	}
	
	
	
	
		
	//Update database
	std::vector<dj::Data> testValues;
	for (int i = 0; i < 10; i++) {
		dj::Data tData = fillTestData(elementsInJ, MAX);
		testValues.push_back(tData);
		testValues.push_back(tData);
	}
	int found = 0;
	int added = 0;
	for (int i = 0; i < std::size(testValues); i++) {
		for (int q = 0; q < elementsInJ; q++) {
			if (testValues[i] == j[q].template get<dj::Data>()) {
				q = elementsInJ;
				found++;
				std::cout << "Part add abort. New part needs unique name and key" << std::endl;
			}
			else if (j[q] == j.back() && testValues[i] != j[q].template get<dj::Data>()) {
				j.push_back(testValues[i]);
				elementsInJ++;
				q = elementsInJ;
				added++;
				std::cout << "Part added" << std::endl;
			}
		}
	}

	dj::Data tData = fillTestData(elementsInJ, MAX);
	tData.key = (rand() % elementsInJ) + 1;
	testValues.clear();

	for (int i = 0; i < elementsInJ; i++) {
		if (j[i]["key"] == tData.key) {
			std::cout << "JSON Part: " << j[i] << " before.\n";
			j[i] = tData;
			std::cout << "JSON Part: " << j[i] << " after." << std::endl;
			i = elementsInJ;
		}
	}

	// -->Add [DONE]
	// -->Update part [DONE]
	// -->Delete part
		
	

}
	
