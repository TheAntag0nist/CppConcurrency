#ifndef BASE_EXAMPLE_H
#define BASE_EXAMPLE_H
#include <core/Singleton.h>
#include <core/Example.h>

class BaseExample : public Example, public Singleton<BaseExample> {
protected:
	BaseExample();
	void HelloWorld();
	friend Singleton<BaseExample>;

public:
	virtual ~BaseExample() = default;
	virtual void Run() override;
};

#endif