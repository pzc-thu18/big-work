#include "table.h"
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

void Table::init(std::string & _info) {
	std::istringstream info(_info);
	std::string data;
	getline(info, data, '(');
	while (getline(info, data, ',')) {
		int x = data.find("PRIMARY KEY");
		if (x != data.npos) {
			//设置主键
			int x1 = data.find_first_of('(');
			int x2 = data.find_first_of(')');
			std::string name = data.substr(x1 + 1, x2 - x1 - 1);
			for (size_t i = 0; i < attr.size(); i++) {
				if (attr[i].first == name) {
					key = i;
					break;
				}
			}
			break;
		}
		
		x = data.find("NOT NULL");
		if (x != data.npos) {
			//设置非空项
			not_null.push_back(items);
			//NOT NULL的位置？
			data.erase(x - 1, 9);
		}


		//需要处理多余的空格(正则化)
		x = data.find(' ');
		std::string name = data.substr(0, x);
		std::string type = data.substr(x + 1);
		attr.push_back(std::pair<std::string, std::string>(name, type));
		items++;
	}
}

void Table::addData(std::string & _info) {
	std::istringstream info(_info);
	std::string data;
	getline(info, data, '(');
	getline(info, data, ')');

	std::vector<int> attrId;
	int x;
	std::string name;
	
	//添加属性
	while (x = data.find_first_of(',') != data.npos) {
		name = data.substr(0,x);
		data = data.substr(x + 1);

		for (int i = 0; i < items; i++) {
			if (attr[i].first == name) {
				attrId.push_back(i);
				break;
			}
		}
	}
	for (int i = 0; i < items; i++) {
		if (attr[i].first == data) {
			attrId.push_back(i);
			break;
		}
	}


	//检查notnull？


	//加入数据
	getline(info, data, '(');
	getline(info, data, ')');
	for (int i = 0; i < items; i++) {
		//查找是否有相应的数据
		int j;
		for (j = 0; j < attrId.size; j++) {
			if (attrId[j] == i) {
				break;
			}
		}
		
		if (j != attrId.size) {
			data.find(',');
		}
	}


}