#pragma once
#include <unordered_map>
#include "table.h"

class Database {
	int table_num = 0;
	std::unordered_map<std::string, Table> tables;
public:
	void setTable(std::string & _info);
	void addData(std::string & _info);
};