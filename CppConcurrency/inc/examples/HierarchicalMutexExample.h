#ifndef HIERARÑHICAL_MUTEX_EXAMPLE_H
#define HIERARÑHICAL_MUTEX_EXAMPLE_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <stdafx.h>

class HierarchicalMutex;
class HierarchyMutexViolation;

class HierarchyMutexViolation : public std::exception {
protected:
	std::string m_message;

public:
	virtual ~HierarchyMutexViolation() = default;
	HierarchyMutexViolation(const HierarchicalMutex& mutex);
	HierarchyMutexViolation(const std::string msg) : m_message(msg) {}

	virtual const char* what() const {
		return m_message.c_str();
	}
};

/// <summary>
/// Can block only lower level mutex.
/// </summary>
class HierarchicalMutex {
private:
	static thread_local uint64_t m_thisThreadHirarchyLevel;
	static uint64_t m_previousHierarchyLevel;
	const uint64_t m_hierarchyLevel;
	std::mutex m_mutex;

protected:
	void CheckHierarchyViolation();
	void UpdateHirarchyLevel();

public:
	HierarchicalMutex(int level);

	void lock();
	bool try_lock();
	void unlock();

	std::string ToString() const;
};

void HighLevelFunc();
void MiddleLevelFunc();
void LowLevelFunc();

class HierarchicalMutexExample : public Example, public Singleton<HierarchicalMutexExample> {
public:
	HierarchicalMutexExample();
	virtual ~HierarchicalMutexExample() = default;
	virtual void Run() override;
};


#endif