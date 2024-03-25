#include <core/ExamplesManager.h>

#include <examples/AccumulateExample.h>
#include <examples/BaseExample.h>
#include <examples/CallExample.h>
#include <examples/DetachExample.h>
#include <examples/FullJoinClassExample.h>
#include <examples/HierarchicalMutexExample.h>
#include <examples/JoinExample.h>
#include <examples/MoveExample.h>
#include <examples/MutexExample.h>
#include <examples/SafeStackExample.h>
#include <examples/SwapExample.h>
#include <examples/ThreadGuardExample.h>
#include <examples/UniqueLockMoveExample.h>

ExamplesManager::ExamplesManager() {
	m_examples.push_back(&BaseExample::GetInstance());
	m_examples.push_back(&CallExample::GetInstance());
	m_examples.push_back(&JoinExample::GetInstance());
	m_examples.push_back(&ThreadGuardExample::GetInstance());
	m_examples.push_back(&DetachExample::GetInstance());
	m_examples.push_back(&MoveExample::GetInstance());
	m_examples.push_back(&FullJoinClassExample::GetInstance());
	m_examples.push_back(&AccumulateExample::GetInstance());
	m_examples.push_back(&MutexExample::GetInstance());
	m_examples.push_back(&SafeStackExample::GetInstance());
	m_examples.push_back(&SwapExample::GetInstance());
	m_examples.push_back(&HierarchicalMutexExample::GetInstance());
	m_examples.push_back(&UniqueLockMoveExample::GetInstance());
}

ExamplesManager& ExamplesManager::GetInstance() {
	static ExamplesManager instance;
	return instance;
}

void ExamplesManager::AddExample(Example& example) {
	m_examples.push_back(&example);
}

const std::vector<Example*>& ExamplesManager::GetExamples() const {
	return m_examples;
}
