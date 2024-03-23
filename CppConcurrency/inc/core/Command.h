#ifndef COMMAND_H
#define COMMAND_H
#include <stdafx.h>

class CommandData {
private:
	std::string m_command;
	std::vector<std::string> m_arguments;

public:
	CommandData() = default;
	CommandData(const std::string& data);
	void Init(const std::string& data);
	virtual ~CommandData() = default;
	void Clear();

	const std::string& GetCommand() const;
	const std::string& GetArgument(int id) const;
	const std::vector<std::string>& GetArguments() const;
};

class Command {
protected:
	std::string m_name;
	std::string m_description;
	CommandData m_commandData;

public:
	Command() = default;
	virtual ~Command() = default;
	
	virtual void Execute() = 0;
	void operator()() { Execute(); }

	std::string GetName() const;
	std::string GetDescription() const;
	void SetCommandData(const std::string& command);

	friend std::ostream& operator<<(std::ostream& os, Command& command);
};

typedef std::shared_ptr<Command> CommandPtr;

#endif