#ifndef CALL_ONCE_H
#define CALL_ONCE_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <stdafx.h>

class SomeResource {
protected:
	std::vector<double> m_data;
public:
	SomeResource() {}
	~SomeResource() {}
};

void InitSomeResource(std::shared_ptr<SomeResource>& resource);

class CallOnceExample : public Example, public Singleton<CallOnceExample> {
protected:
	CallOnceExample();
	friend Singleton<CallOnceExample>;

public:
	virtual ~CallOnceExample() = default;
	virtual void Run() override;

};

#endif