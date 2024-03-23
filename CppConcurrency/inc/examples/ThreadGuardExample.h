#ifndef THREAD_GUARD_EXAMPLE_H
#define THREAD_GUARD_EXAMPLE_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <stdafx.h>

class ThreadGuard {
private:
	std::thread& m_thread;

protected:
	ThreadGuard(const ThreadGuard& guard) = delete;
	ThreadGuard& operator=(const ThreadGuard& guard) = delete;

public:
	explicit ThreadGuard(std::thread& t);
	virtual ~ThreadGuard();
};

class ThreadGuardExample : public Example, public Singleton<ThreadGuardExample> {
protected:
	ThreadGuardExample();
	friend Singleton<ThreadGuardExample>;

public:
	virtual ~ThreadGuardExample() = default;
	virtual void Run() override;
};

#endif