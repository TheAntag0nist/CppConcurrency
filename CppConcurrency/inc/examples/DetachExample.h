#ifndef DETACH_EXAMPLE_H
#define DETACH_EXAMPLE_H
#include <core/Singleton.h>
#include <core/Example.h>

class DetachExample : public Example, public Singleton<DetachExample> {
private:
	DetachExample();
	friend Singleton<DetachExample>;

public:
	virtual ~DetachExample() = default;
	virtual void Run() override;
};

#endif