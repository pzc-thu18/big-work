#include "system.h"

void System::addBase(const std::string & name) {
//未考虑重命名的情况
	Database base;
	bases.insert(std::pair<std::string, Database>(name, base));
	base_num++;
}