#ifndef UNIQUE_LOCK_MOVE_EXAMPLE_H
#define UNIQUE_LOCK_MOVE_EXAMPLE_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <stdafx.h>

class UniqueLockMoveExample : public Example, public Singleton<UniqueLockMoveExample> {
protected:
	UniqueLockMoveExample();
	friend Singleton<UniqueLockMoveExample>;
	std::unique_lock<std::mutex> GetLock();

public:
	virtual ~UniqueLockMoveExample() = default;
	virtual void Run() override;
};
#endif