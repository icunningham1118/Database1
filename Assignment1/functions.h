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
#include <cstdio>
#include "json.hpp"
#include "data.h"
using json = nlohmann::json;
void parseTable(std::vector<dj::Data>&);
void serializeData(std::vector<dj::Data>&);
void initialBuildDatabase();
void logCheck();
void writeLog();
bool readLog();
std::string getRandomStr();
float getRandomFloat();
dj::Data fillTestData(int,int);
void testSuite();
void testSearchKey();
void testSearchName();
void testSearchType();
void testSearchBrand();

#endif /*FUNCTIONS_H*/