#pragma once
#include "database.h"

class System {
	int base_num;
	Database * cur_base;
	std::unordered_map<std::string, Database> bases;
public:
	void addBase(const std::string & name); 

	void setBase(const std::string & name) {
		//Î´¿¼ÂÇÕÒ²»µ½µÄÇé¿ö
		cur_base = &bases[name];
	}

	void setTable(std::string & _info) {
		cur_base->setTable(_info);
	}

	void addData(std::string & _info) {
		cur_base->addData(_info);
		
	}
	void showBase(std::string & database_name){
		std::cout<<database_name<<std::endl;//输出数据库名称 
		bases[database_name].show_tablename_info();//输出表单 
	}
	 
	
	void showTable(std::string & table_name){
		cur_base->find_table(table_name);
	}
};
