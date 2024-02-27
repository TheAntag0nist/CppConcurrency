#ifndef BASE_EXAMPLE_H
#define BASE_EXAMPLE_H
#include <Example.h>

class BaseExample : public Example {
protected:
	void HelloWorld();

public:
	BaseExample();
	virtual ~BaseExample() = default;

	virtual void Run() override;
};

#endif