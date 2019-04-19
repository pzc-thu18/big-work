#include "database.h"
#include <sstream>
#include <iostream>

void Database::setTable(std::string & _info) {
	std::istringstream info(_info);
	std::string Tablename;
	getline(info, Tablename, '(');

	Table table;
	table.init(_info);
	tables[Tablename] = table;
	table_num++;
}

void Database::addData(std::string & _info) {
	std::istringstream info(_info);
	std::string Tablename;
	info >> Tablename;
	getline(info, Tablename, '(');
	tables[Tablename].addData(_info);
}