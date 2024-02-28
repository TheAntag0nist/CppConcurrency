#ifndef CLASS_CALL_OPERATOR_H
#define CLASS_CALL_OPERATOR_H
#include <core/Singleton.h>
#include <core/Example.h>

class Call {
public:
	void operator()() const {
		std::cout << "[Call] operator()\n";
	}
};

class CallExample : public Example, public Singleton<CallExample> {
protected:
	CallExample();
	friend Singleton<CallExample>;

public:
	virtual ~CallExample() = default;
	virtual void Run() override;
};

#endif