#include <core/ExamplesManager.h>

#include <examples/BaseExample.h>
#include <examples/CallExample.h>
#include <examples/JoinExample.h>

ExamplesManager::ExamplesManager() {
	m_examples.push_back(ExamplePtr(&BaseExample::GetInstance()));
	m_examples.push_back(ExamplePtr(&CallExample::GetInstance()));
	m_examples.push_back(ExamplePtr(&JoinExample::GetInstance()));
}

ExamplesManager& ExamplesManager::GetInstance() {
	static ExamplesManager instance;
	return instance;
}

const std::vector<ExamplePtr>& ExamplesManager::GetExamples() const {
	return m_examples;
}
