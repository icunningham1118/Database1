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
		int i = 0;
		std::cout << "First time user, building database..." << std::endl;

		//Builds database
		if (initialBuildDatabase()) {
			std::cout << "Database has been built!" << std::endl;
			i = 1;
		}
		else {
			std::cout << "Database failed to build. Ensure you have included \"part.tbl\" file with your install." << std::endl;
		}

		//Updates log to 1
		writeLog(i);
	}
	else {
		//Launching program after 1st build will display this message
		std::cout << "Welcome back!" << std::endl;
	}
	if (readLog()) {
		std::vector<dj::Data> dataVec = loadDatabase();
		// Menu loop
		int choice;
		do {
			choice = getMenuChoice();

			switch (choice) {
			case 1: insertPart(dataVec); break;
			case 2: searchParts(dataVec); break;
			case 3: updatePart(dataVec); break;
			case 4: deletePart(dataVec); break;
			case 5: testSuite(); break;
			case 6: saveDatabase(dataVec); std::cout << "Exiting...\n"; break;
			default: std::cout << "Invalid choice.\n";
			}
		} while (choice != 6);
	}
	else {
		std::cout << "Exiting...\n";
	}
	return 0;
}