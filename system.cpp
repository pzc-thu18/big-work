#include "system.h"

void System::addBase(const std::string & name) {
//δ���������������
	Database base;
	bases.insert(std::pair<std::string, Database>(name, base));
	base_num++;
}