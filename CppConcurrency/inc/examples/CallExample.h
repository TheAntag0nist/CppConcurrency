#ifndef CLASS_CALL_OPERATOR_H
#define CLASS_CALL_OPERATOR_H
#include <Example.h>

class Call {
public:
	void operator()() const {
		std::cout << "[Call] operator()\n";
	}
};

class CallExample : public Example {
public:
	CallExample();
	virtual ~CallExample() = default;

	virtual void Run() override;
};

#endif