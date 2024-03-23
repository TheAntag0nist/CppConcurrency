#include <examples/HierarchicalMutexExample.h>

#pragma region - Exceptions -
HierarchyMutexViolation::HierarchyMutexViolation(const HierarchicalMutex& mutex) {
	m_message = mutex.ToString();
}
#pragma endregion

#pragma region - Hierarchy Mutex -
thread_local uint64_t HierarchicalMutex::m_thisThreadHirarchyLevel = ULONG_MAX;
uint64_t HierarchicalMutex::m_previousHierarchyLevel = ULONG_MAX;

HierarchicalMutex::HierarchicalMutex(int level) : m_hierarchyLevel(level) {}

void HierarchicalMutex::CheckHierarchyViolation() {
	if (m_previousHierarchyLevel <= m_hierarchyLevel) 
		throw HierarchyMutexViolation(*this);
}

void HierarchicalMutex::UpdateHirarchyLevel() {
	// TODO: Think about order
	m_thisThreadHirarchyLevel = m_hierarchyLevel;
	m_previousHierarchyLevel = m_thisThreadHirarchyLevel;
}

void HierarchicalMutex::lock() {
	CheckHierarchyViolation();
	m_mutex.lock();
	UpdateHirarchyLevel();
}

bool HierarchicalMutex::try_lock() {
	CheckHierarchyViolation();
	if (!m_mutex.try_lock())
		return false;
	UpdateHirarchyLevel();
	return true;
}

void HierarchicalMutex::unlock() {
	m_mutex.unlock();
}

std::string HierarchicalMutex::ToString() const {
	std::stringstream ss;
	ss << "Mutex level: " << m_hierarchyLevel << std::endl
		<< "This Thread Level: " << m_thisThreadHirarchyLevel << std::endl
		<< "Previous Hirarchy Level: " << m_previousHierarchyLevel;
	return ss.str();
}
#pragma endregion

#pragma region - Example - 

HierarchicalMutexExample::HierarchicalMutexExample() {
	m_id = m_counter++;
	m_name = "Hirarchycal Mutex Example";
	m_description = "Example of Hierarchycal mutex that you can use for writting deadlock safe code.";
}

HierarchicalMutex mutexLevel1(10'000);
HierarchicalMutex mutexLevel2(8'000);
HierarchicalMutex mutexLevel3(6'000);

void HighLevelFunc() {
	std::scoped_lock guard(mutexLevel1);
	std::cout << "[HIGH_LEVEL]\n";
	LowLevelFunc();
}

void MiddleLevelFunc() {
	std::scoped_lock guard(mutexLevel2);
	std::cout << "[MIDDLE_LEVEL]\n";
};

void LowLevelFunc() {
	std::scoped_lock guard(mutexLevel3);
	std::cout << "[LOW_LEVEL]\n";
};

void HierarchicalMutexExample::Run() {
	std::scoped_lock guard1(mutexLevel1);
	std::scoped_lock guard2(mutexLevel3);
	std::scoped_lock guard3(mutexLevel2);
}
#pragma endregion
