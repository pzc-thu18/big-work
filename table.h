#pragma once
#include <list>
#include <string>
#include <string.h>
#include <vector>

class Table {
	//行数
	int row_num = 0;
	//属性数
	int items = 0;
	//数据信息:名字+类型
	std::vector< std::pair<std::string,std::string> > attr;
	//具体信息,全部存成string,不同属性用','间隔
	std::list<std::string> rows;
	//KEY
	int key = -1;
	//NOT NULL
	std::vector<int> not_null;
public:
	void init(std::string & _info);
	void addData(std::string & _info);
};
