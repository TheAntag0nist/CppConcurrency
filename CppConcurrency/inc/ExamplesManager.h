#ifndef EXAMPLES_MANAGER_H
#define EXAMPLES_MANAGER_H
#include <Example.h>
#include <stdafx.h>

class ExampleManager {
private:
	std::vector<Example> m_examples;

protected:
	ExampleManager() = default;
	void operator=(const ExampleManager& manager) = delete;
	ExampleManager(const ExampleManager& manager) = delete;

public:
	~ExampleManager() = default;
	static ExampleManager& GetInstance();

};

#endif