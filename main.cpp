#include "system.h"
#include <iostream>
#include <utility>

int main() {
	System system;
	while (true) {
		static std::string order;
		//输入命令
		std::cin >> order;
		//创建数据库或表单
		if (order == "CREATE") {
			std::cin >> order;
			if (order == "DATABASE") {
				getline(std::cin, order, ';');
				system.addBase(order);
			}
			else if (order == "TABLE") {
				getline(std::cin, order, ';');
				system.setTable(order);
			}
			else {
				std::cout << "WTF??" << std::endl;
			}
		}
		//删除数据库
		else if (order == "DROP") {

		}
		//切换数据库
		else if (order == "USE") {
			getline(std::cin, order, ';');
			system.setBase(order);
		}
		//列出所有数据库及其包含的所有表名
		else if (order == "INSERT") {
			getline(std::cin, order, ';');
			system.addData(order);
		}
		else if (order == "SHOW") {

		}
		//表的数据删除
		else if (order == "DELETE") {

		}
		//表的数据修改
		else if (order == "UPDATE") {

		}
		//表的查询
		//实现whereClauses语句
		else if (order == "select") {

		}
		else {
			std::cout << "WTF??" << std::endl;
		}
	}
}