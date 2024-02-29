#include <core/ExamplesManager.h>

#include <examples/BaseExample.h>
#include <examples/CallExample.h>
#include <examples/JoinExample.h>
#include <examples/ThreadGuardExample.h>
#include <examples/DetachExample.h>
#include <examples/MoveExample.h>
#include <examples/FullJoinClassExample.h>

ExamplesManager::ExamplesManager() {
	m_examples.push_back(ExamplePtr(&BaseExample::GetInstance()));
	m_examples.push_back(ExamplePtr(&CallExample::GetInstance()));
	m_examples.push_back(ExamplePtr(&JoinExample::GetInstance()));
	m_examples.push_back(ExamplePtr(&ThreadGuardExample::GetInstance()));
	m_examples.push_back(ExamplePtr(&DetachExample::GetInstance()));
	m_examples.push_back(ExamplePtr(&MoveExample::GetInstance()));
	m_examples.push_back(ExamplePtr(&FullJoinClassExample::GetInstance()));
}

ExamplesManager& ExamplesManager::GetInstance() {
	static ExamplesManager instance;
	return instance;
}

void ExamplesManager::AddExample(ExamplePtr example) {
	m_examples.push_back(example);
}

const std::vector<ExamplePtr>& ExamplesManager::GetExamples() const {
	return m_examples;
}
