#ifndef FUNC_H
#define FUNC_H
#include <stdafx.h>

struct Func {
	int& value;
	Func(int& v) : value(v) { }

	void operator()();
	void DoSomething();
};

#endif