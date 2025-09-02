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
	if (!std::filesystem::exists(LOGNAME)) {
		//Log file is created if program is run for the first time. 
		//LOGNAME = "log.txt"
		//NOTE:: Unable to get this section to compile in any other place besides Visual Studio. Might need to be removed.
		std::ofstream logCreate{ LOGNAME };
		logCreate << 0;
		logCreate.close();
	}
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
		dj::Data d1;
		int key = (rand() % 20000) + 1;

		std::cout << "searching for key: " << key << std::endl;
		for (int i = 0; i < size(j); i++) {
			if (j[i]["key"] == key) {
				d1 = j[i].template get<dj::Data>();
				i = size(j);
			}
		}
		std::cout << d1.key << " " << d1.name << " " << d1.brand << " " << d1.type << std::endl;
		
		std::vector<dj::Data> testData;
		for (auto& e : j) {
			testData.push_back(e.template get<dj::Data>());
		}
		key = (rand() % 20000);
		std::cout << "searching for name: " << testData[key].name << std::endl;
		std::string testString = testData[key].name;
		for (int i = 0; i < size(j); i++) {
			if (j[i]["name"] == testString) {
				d1 = j[i].template get<dj::Data>();
				i = size(j);
			}
		}
		std::cout << d1.key << " " << d1.name << " " << d1.brand << " " << d1.type << std::endl;

		key = (rand() % 20000);
		std::cout << "searching for brands: " << testData[key].brand << std::endl;
		testString = testData[key].brand;
		int c = 0;
		std::vector<dj::Data> multiFind;
		for (int i = 0; i < size(j); i++) {
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
		key = (rand() % 20000);
		std::cout << "searching for types: " << testData[key].type << std::endl;
		testString = testData[key].type;

		c = 0;

		for (int i = 0; i < size(j); i++) {
			if (j[i]["type"] == testString) {
				multiFind.push_back(j[i].template get<dj::Data>());
				c++;
			}
		}
		std::cout << "Found " << c << " different items from " << testString << "type.\n";
		for (auto& e : multiFind) {
			std::cout << e.key << " " << e.name << " " << e.brand << " " << e.type << std::endl;
		}
		// -->By key
		// -->By name
		// -->By brand
		// -->By type

		//Update database
		// -->Add
		// -->Update part
		// -->Delete part
		
	

}
	
