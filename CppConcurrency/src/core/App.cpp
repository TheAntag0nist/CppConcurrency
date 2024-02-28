#include <core/App.h>

App::App() {
	m_isWorking = true;

	CommandPtr cmdPtr = CommandPtr(new ShowExamplesCommand);
	m_commands[cmdPtr->GetName()] = cmdPtr;
	
	cmdPtr = CommandPtr(new ExitCommand(&m_isWorking));
	m_commands[cmdPtr->GetName()] = cmdPtr;

	cmdPtr = CommandPtr(new HelpCommand(m_commands));
	m_commands[cmdPtr->GetName()] = cmdPtr;
}

App& App::GetInstance() {
	static App instance;
	return instance;
}

void App::ExecuteCommand(const std::string& command) {
	try {
		auto item = m_commands.find(command);
		if (item == m_commands.end()) {
			std::cout << "[!!]:> Unknown command. Enter -help\n";
			return;
		}

		CommandPtr& cmd = item->second;
		cmd->Execute();
	}
	catch (std::exception& ex) {
		std::cout << "[INNER_EXCEPTION]:> " << ex.what();
	}
}

bool App::IsWorking() const {
	return m_isWorking;
}