#include <core/Command.h>

CommandData::CommandData(const std::string& data) {
	Init(data);
}

void CommandData::Init(const std::string& data) {
	Clear();

	std::stringstream ss(data);
	if(!ss.eof())
		ss >> m_command;

	while (!ss.eof()) {
		std::string temp;
		ss >> temp;
		m_arguments.push_back(temp);
	}
}

void CommandData::Clear() {
	m_arguments.clear();
	m_command = "";
}

const std::string& CommandData::GetCommand() const {
	return m_command;
}

const std::string& CommandData::GetArgument(int id) const {
	return m_arguments[id];
}

const std::vector<std::string>& CommandData::GetArguments() const {
	return m_arguments;
}

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

void Command::SetCommandData(const std::string& command) {
	m_commandData.Init(command);
}