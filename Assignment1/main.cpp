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
	std::fstream log;
	log.open(LOGNAME, std::ios::in | std::ios::out);
	int logFlag;
	log >> logFlag;

	if (!logFlag) {
		//TODO: Split whole section into functions.
		std::cout << "First time user, building database..." << std::endl;

		//Opening database and table files
		std::ofstream dBase;
		std::ifstream table;

		const char delim = '|';
		table.open("test.tbl");

		//This file will not be included when sending project
		dBase.open("database.json");

		//Getting the information from the table file.
		//Each part has nine attributes so each attribute gets its own read and
		//is put into a data struct for serialization at the end of the loop.

		//Each line is read at the beginning of each loop and is turned into a 
		//stringstream which allows us to loop through and retrieve the relevant data.
		std::string line;
		while (std::getline(table, line)) {

			std::string tline;
			Data tData;

			//ordered_json so it will be in the same order as it is read from part.tbl
			nlohmann::ordered_json jObject;
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

			//Here we is the template for our JSON object
			//This is the order it will appear in the JSON
			//file.
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

			//Actually adding the JSON object to the JSON 
			//file (our databae)
			dBase << jObject;
		}
			//TODO: overwrite log file to show 1 instead of 0 so subsequent
			// launches of the program do not automatically rebuild the database
			//key, name, mfgr, brand, type, size, container, price, comment
			table.close();
			log.close();
			dBase.close();
	}

}
	
