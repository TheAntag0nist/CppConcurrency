#include <core/Func.h>

void Func::operator()() {
	DoSomething();
}

void Func::DoSomething() {
	for (uint32_t iter = 0; iter < 100; ++iter)
		std::cout << "Thread ID: " << value << " " << iter << std::endl;
}