#pragma once
#include <list>
#include <string>
#include <string.h>
#include <vector>

class Table {
	//����
	int row_num = 0;
	//������
	int items = 0;
	//������Ϣ:����+����
	std::vector< std::pair<std::string,std::string> > attr;
	//������Ϣ,ȫ�����string,��ͬ������','���
	std::list<std::string> rows;
	//KEY
	int key = -1;
	//NOT NULL
	std::vector<int> not_null;
public:
	void init(std::string & _info);
	void addData(std::string & _info);
};
