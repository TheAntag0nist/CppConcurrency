#ifndef SWAP_EXAMPLE_H
#define SWAP_EXAMPLE_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <stdafx.h>

class SomeBigObject {
protected:
	std::vector<int> m_data;
	std::mutex m_mutex;

public:
	SomeBigObject(size_t size);
	virtual ~SomeBigObject() = default;
	void Swap(SomeBigObject& obj);
	size_t GetSize();
};

class SwapExample : public Example, public Singleton<SwapExample> {
protected:
	SwapExample();
	friend Singleton<SwapExample>;

public:
	virtual ~SwapExample() = default;
	virtual void Run() override;
};

#endif