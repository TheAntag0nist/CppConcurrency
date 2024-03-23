#ifndef EXAMPLES_MANAGER_H
#define EXAMPLES_MANAGER_H
#include <core/Example.h>
#include <stdafx.h>

class ExamplesManager {
private:
	std::vector<Example*> m_examples;

protected:
	ExamplesManager();
	void operator=(const ExamplesManager& manager) = delete;
	ExamplesManager(const ExamplesManager& manager) = delete;

public:
	~ExamplesManager() = default;
	static ExamplesManager& GetInstance();

	void AddExample(Example& example);
	const std::vector<Example*>& GetExamples() const;
};

#endif