#include "system.h"
#include <iostream>
#include <utility>

int main() {
	System system;
	while (true) {
		static std::string order;
		//��������
		std::cin >> order;
		//�������ݿ���
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
		//ɾ�����ݿ�
		else if (order == "DROP") {

		}
		//�л����ݿ�
		else if (order == "USE") {
			getline(std::cin, order, ';');
			system.setBase(order);
		}
		//�г��������ݿ⼰����������б���
		else if (order == "INSERT") {
			getline(std::cin, order, ';');
			system.addData(order);
		}
		else if (order == "SHOW") {

		}
		//�������ɾ��
		else if (order == "DELETE") {

		}
		//��������޸�
		else if (order == "UPDATE") {

		}
		//��Ĳ�ѯ
		//ʵ��whereClauses���
		else if (order == "select") {

		}
		else {
			std::cout << "WTF??" << std::endl;
		}
	}
}