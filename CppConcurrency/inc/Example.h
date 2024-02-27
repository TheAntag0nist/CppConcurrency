#ifndef EXAMPLE_H
#define EXAMPLE_H
#include <stdafx.h>

class Example {
protected:
	static uint32_t m_counter;
	std::string m_description;
	std::string m_name;
	uint32_t m_id;

public:
	Example() = default;
	virtual ~Example() = default;

	virtual void Run() = 0;

	uint32_t GetId() const;
	std::string GetName() const;
	std::string GetDescription() const;

	friend std::ostream& operator<<(std::ostream& os, const Example& ex);
};

#endif