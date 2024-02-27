#include <examples/BaseExample.h>

BaseExample::BaseExample() {
	m_description = "It's 'Hello World' in concurrency world.\n"
		"Usually, to solve such a simple task, it makes no sense\n"
		"to create a thread, especially when the main one is free\n";
	m_name = "Basic example";
	m_id = m_counter++;
}

void BaseExample::HelloWorld() {
	std::cout << "Hello Concurrent World!\n";
}

void BaseExample::Run() {
	std::thread helloThread(&BaseExample::HelloWorld, this);
	helloThread.join();
}