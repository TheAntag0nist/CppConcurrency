#include <examples/CallExample.h>

CallExample::CallExample() {
	m_description = "It's 'Hello World' in concurrency world.\n";
	m_name = "Class Call Operator example";
	m_id = m_counter++;
}

void CallExample::Run() {
	Call callObject;
	std::thread callThread(callObject);
	callThread.join();
}