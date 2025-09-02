#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define LOG "log.txt"
#define PARTTABLE "part.tbl"
#define DATABASE "database.json"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "json.hpp"
#include "data.h"
using json = nlohmann::json;
bool parseTable(std::vector<dj::Data>&);
bool serializeData(std::vector<dj::Data>&);
bool buildDatabase();
void writeLog();
bool readLog();
std::string getRandomStr();
float getRandomFloat();
#endif /*FUNCTIONS_H*/