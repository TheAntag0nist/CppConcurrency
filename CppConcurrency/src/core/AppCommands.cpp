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

	for (Example* ex : examples) {
		std::cout << std::right << std::setw(6) << ex->GetId() << ": " 
				<< std::setw(6) << ex->GetName() << std::endl;
	}
}


RunExampleCommand::RunExampleCommand() {
	m_name = "run_ex";
	m_description = "run example";
}

void RunExampleCommand::Execute() {
	auto& examplesManager = ExamplesManager::GetInstance();
	auto& args = m_commandData.GetArguments();
	if (args.empty()) {
		std::cout << "[ERR]:> Incorrect ID of example\n";
		return;
	}

	bool isNumber = std::regex_match(args[0], std::regex("[0-9]+"));
	if (!isNumber) {
		std::cout << "[ERR]:> It's not number. Should be Example ID\n";
		return;
	}
	
	uint32_t id = std::stoi(args[0]);
	auto& examples = examplesManager.GetExamples();
	
	if (examples.size() > id) {
		std::thread exampleThread(
			[](Example* ex) { ex->Run(); },
			std::ref(examples[id])
		);
		exampleThread.join();
	}
	else {
		std::cout << "[ERR]:> Invalid Example ID\n";
		return;
	}
}
