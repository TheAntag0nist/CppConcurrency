#include <core/AppCommands.h>

ExitCommand::ExitCommand(bool* var) {
	m_name = "exit";
	m_description = "exit from application";
	m_variable = var;
}

void ExitCommand::Execute() {
	*m_variable = false;
}

HelpCommand::HelpCommand(std::map<std::string, CommandPtr>& commands) : m_commands(commands) {
	m_name = "help";
	m_description = "display that window";
}

void HelpCommand::Execute() {
	for (auto& item : m_commands)
		std::cout << (*item.second) << std::endl;
}

ShowExamplesCommand::ShowExamplesCommand() {
	m_name = "examples";
	m_description = "show list of concurrent examples";
}

void ShowExamplesCommand::Execute() {
	ExamplesManager& examplesManager = ExamplesManager::GetInstance();
	const auto& examples = examplesManager.GetExamples();

	for (ExamplePtr ex : examples) {
		std::cout << std::right << std::setw(6) << ex->GetId() << ": " 
				<< std::setw(6) << ex->GetName() << std::endl;
	}
}
