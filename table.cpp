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
			//��������
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
			//���÷ǿ���
			not_null.push_back(items);
			//NOT NULL��λ�ã�
			data.erase(x - 1, 9);
		}


		//��Ҫ�������Ŀո�(����)
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
	
	//�������
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


	//���notnull��


	//��������
	getline(info, data, '(');
	getline(info, data, ')');
	for (int i = 0; i < items; i++) {
		//�����Ƿ�����Ӧ������
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