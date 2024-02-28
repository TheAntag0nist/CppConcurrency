#ifndef APP_COMMANDS_H
#define APP_COMMANDS_H
#include <core/ExamplesManager.h>
#include <core/Command.h>
#include <stdafx.h>

class ExitCommand : public Command {
private:
	bool* m_variable;

public:
	ExitCommand(bool* var);
	ExitCommand() = default;
	virtual void Execute() override;
};

class HelpCommand : public Command {
private:
	std::map<std::string, CommandPtr>& m_commands;

public:
	HelpCommand() = delete;
	virtual ~HelpCommand() = default;
	HelpCommand(std::map<std::string, CommandPtr>& commands);
	virtual void Execute() override;
};

class ShowExamplesCommand : public Command {
public:
	ShowExamplesCommand();
	virtual ~ShowExamplesCommand() = default;
	virtual void Execute() override;
};

#endif