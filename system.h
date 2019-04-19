#pragma once
#include "database.h"

class System {
	int base_num;
	Database * cur_base;
	std::unordered_map<std::string, Database> bases;
public:
	void addBase(const std::string & name); 

	void setBase(const std::string & name) {
		//未考虑找不到的情况
		cur_base = &bases[name];
	}

	void setTable(std::string & _info) {
		cur_base->setTable(_info);
	}

	void addData(std::string & _info) {
		cur_base->addData(_info);
	}
};