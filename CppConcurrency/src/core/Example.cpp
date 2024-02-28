#include <core/Example.h>

std::ostream& operator<<(std::ostream& os, const Example& ex) {
	os << "Id :" << ex.GetId() << std::endl;
	os << "Name: " << ex.GetName() << std::endl;
	os << "Description: \n" << ex.GetDescription() << std::endl;
	return os;
}

uint32_t Example::m_counter = 0;
uint32_t Example::GetId() const { return m_id; }
std::string Example::GetName() const { return m_name; }
std::string Example::GetDescription() const { return m_description; }