#include <ExamplesManager.h>

ExampleManager& ExampleManager::GetInstance() {
	static ExampleManager instance;
	return instance;
}
