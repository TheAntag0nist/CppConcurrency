#ifndef SWAP_EXAMPLE_H
#define SWAP_EXAMPLE_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <stdafx.h>

class SwapExample : public Example, public Singleton<SwapExample> {
protected:
	SwapExample();
	friend Singleton<SwapExample>;

public:
	virtual ~SwapExample() = default;
	virtual void Run() override;
};

#endif