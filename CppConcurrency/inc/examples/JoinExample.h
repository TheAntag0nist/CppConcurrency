#ifndef JOIN_EXAMPLE_H
#define JOIN_EXAMPLE_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <core/Func.h>

class JoinExample : public Example, public Singleton<JoinExample> {
protected:
	JoinExample();
	friend Singleton<JoinExample>;

public:
	virtual ~JoinExample() = default;
	virtual void Run() override;
};

#endif