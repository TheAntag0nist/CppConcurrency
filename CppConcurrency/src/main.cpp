#include <core/ExamplesManager.h>
#include <core/App.h>

int main() {
	App& app = App::GetInstance();
	
	while (app.IsWorking()) {
		std::string command = "";
		std::cout << "cpp_concurrent:> ";
		std::getline(std::cin, command);
		app.ExecuteCommand(command);
	}

	return 0;
}