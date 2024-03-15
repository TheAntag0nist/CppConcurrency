#ifndef ADDER_EXAMPLE_H
#define ADDER_EXAMPLE_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <stdafx.h>

class AdderExample : public Example, public Singleton<AdderExample> {
protected:
	friend Singleton<AdderExample>;

public:
	AdderExample();
	virtual ~AdderExample() = default;
	virtual Run() override;
};


#endif