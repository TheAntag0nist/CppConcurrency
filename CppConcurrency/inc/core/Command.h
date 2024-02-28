#ifndef COMMAND_H
#define COMMAND_H
#include <stdafx.h>

class Command {
protected:
	std::string m_name;
	std::string m_description;

public:
	Command() = default;
	virtual ~Command() = default;
	
	virtual void Execute() = 0;
	void operator()() { Execute(); }

	std::string GetName() const;
	std::string GetDescription() const;

	friend std::ostream& operator<<(std::ostream& os, Command& command);
};

typedef std::shared_ptr<Command> CommandPtr;

#endif