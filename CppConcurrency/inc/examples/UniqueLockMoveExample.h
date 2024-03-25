#ifndef UNIQUE_LOCK_MOVE_EXAMPLE_H
#define UNIQUE_LOCK_MOVE_EXAMPLE_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <stdafx.h>

class UniqueLockMoveExample : public Example, public Singleton<UniqueLockMoveExample> {
protected:
	std::unique_lock<std::mutex> GetLock();

public:
	UniqueLockMoveExample();
	virtual ~UniqueLockMoveExample() = default;
	virtual void Run() override;
};
#endif