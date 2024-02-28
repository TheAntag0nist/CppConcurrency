#include <core/Command.h>

std::string Command::GetName() const {
	return m_name;
}

std::string Command::GetDescription() const {
	return m_description;
}

std::ostream& operator<<(std::ostream& os, Command& command) {
	os << std::right << std::setw(14) << command.m_name 
		<< std::setw(3) << " - " << std::left 
		<< std::setw(32) << command.m_description;
	return os;
}