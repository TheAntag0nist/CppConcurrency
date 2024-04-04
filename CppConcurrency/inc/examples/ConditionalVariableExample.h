#ifndef CONDITIONAL_VARIABLE_EXAMPLE_H
#define CONDITIONAL_VARIABLE_EXAMPLE_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <stdafx.h>

class DataChunk {
public:
	std::vector<double> data;
};

class ConditionalVariableExample : public Example, public Singleton<ConditionalVariableExample> {
private:
	std::condition_variable m_condition;
	std::queue<DataChunk> m_chunks;
	const size_t m_dataSize = 10;
	std::mutex m_mutex;

protected:
	ConditionalVariableExample();
	friend Singleton<ConditionalVariableExample>;

	void DataPreparationThread();
	void DataProcessThread();

public:
	virtual ~ConditionalVariableExample() = default;
	virtual void Run() override;
};

#endif