#include <ExamplesManager.h>
#include <examples/BaseExample.h>
#include <examples/CallExample.h>

int main() {
	ExampleManager& exManager = ExampleManager::GetInstance();
	bool isWorking = true;

	BaseExample example;
	example.Run();

	CallExample callExample;
	callExample.Run();

	std::cout << example;
	return 0;
}