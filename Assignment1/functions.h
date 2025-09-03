#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX 30000

#define LOG "log.txt"
#define PARTTABLE "part.tbl"
#define DATABASE "database.json"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <random>
#include "json.hpp"
#include "data.h"
using json = nlohmann::json;

bool parseTable(std::vector<dj::Data>&);
bool serializeData(std::vector<dj::Data>&);
bool initialBuildDatabase();
void logCheck();
void writeLog(int);
bool readLog();

std::vector<dj::Data> loadDatabase();
void saveDatabase(std::vector<dj::Data>&);

int getMenuChoice();
void insertPart(std::vector<dj::Data>&);
void searchParts(std::vector<dj::Data>&);
void updatePart(std::vector<dj::Data>&);
void deletePart(std::vector<dj::Data>&);

std::string getRandomStr();
float getRandomFloat();
dj::Data fillTestData(int,int);

void testSuite();
void testSearchKey(json&, size_t&);
void testSearchName(json&,std::vector<dj::Data>&, size_t&);
void testSearchType(json&, std::vector<dj::Data>&, size_t&);
void testSearchBrand(json&, std::vector<dj::Data>&, size_t&);

void testAdd(json&, std::vector<dj::Data>&, size_t&);
dj::Data testUpdate(json&, size_t&);
void testDelete(json&, size_t&, dj::Data);

#endif /*FUNCTIONS_H*/