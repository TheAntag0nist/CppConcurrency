#ifndef MUTEX_EXAMPLE_H
#define MUTEX_EXAMPLE_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <stdafx.h>

class MutexExample : public Example, public Singleton<MutexExample> {
private:
	std::list<uint32_t> someList;
	std::mutex m_mutex;

protected:
	MutexExample();
	friend Singleton<MutexExample>;

	void AddToList(uint32_t value);
	bool ListContains(uint32_t value);

public:
	virtual ~MutexExample() = default;
	virtual void Run() override;
};

#endif