#ifndef ACCUMULATE_EXAMPLE_H
#define ACCUMULATE_EXAMPLE_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <stdafx.h>

template <typename Iterator, typename T>
struct AccumulateBlock {
	void operator()(Iterator begin, Iterator last, T& result) {
		result = std::accumulate(begin, last, 0);
	}
};

class AccumulateExample : public Example, public Singleton<AccumulateExample>{
protected:
	AccumulateExample();
	friend Singleton<AccumulateExample>;

	template <typename Iterator, typename T>
	T Accumulate(Iterator first, Iterator last, T init);

	template <typename Iterator, typename T>
	T ParallelAccumulate(Iterator first, Iterator last, T init);

public:
	virtual ~AccumulateExample() = default;
	virtual void Run() override;
};

#endif