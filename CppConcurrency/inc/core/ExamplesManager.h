#ifndef EXAMPLES_MANAGER_H
#define EXAMPLES_MANAGER_H
#include <core/Example.h>
#include <stdafx.h>

class ExamplesManager {
private:
	std::vector<ExamplePtr> m_examples;

protected:
	ExamplesManager();
	void operator=(const ExamplesManager& manager) = delete;
	ExamplesManager(const ExamplesManager& manager) = delete;

public:
	~ExamplesManager() = default;
	static ExamplesManager& GetInstance();

	const std::vector<ExamplePtr>& GetExamples() const;
};

#endif