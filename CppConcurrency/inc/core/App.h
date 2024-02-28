#ifndef APP_H
#define APP_H
#include <core/AppCommands.h>

class App {
private:
	std::map<std::string, CommandPtr> m_commands;
	bool m_isWorking;

protected:
	App();
	App(const App& app) = delete;

public:
	virtual ~App() = default;
	static App& GetInstance();

	void ExecuteCommand(const std::string& command);
	bool IsWorking() const;
};

#endif