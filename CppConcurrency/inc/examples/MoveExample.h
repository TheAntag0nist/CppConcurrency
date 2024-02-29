#ifndef MOVE_EXAMPLE_H
#define MOVE_EXAMPLE_H
#include <core/ExamplesManager.h>
#include <core/Singleton.h>
#include <core/Example.h>
#include <core/Func.h>
#include <stdafx.h>

class ScopedThread {
private:
	std::thread m_thread;

protected:
	ScopedThread(const ScopedThread& scopedThread) = delete;
	ScopedThread& operator=(const ScopedThread& scopedThread) = delete;

public:
	explicit ScopedThread(std::thread t);
	~ScopedThread();
};

class MoveExample : public Example, public Singleton<MoveExample> {
protected:
	MoveExample();
	friend Singleton<MoveExample>;

public:
	virtual ~MoveExample() = default;
	virtual void Run() override;
};

#endif