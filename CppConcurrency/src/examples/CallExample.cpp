#include <examples/CallExample.h>

CallExample::CallExample() {
	m_description = "It's example of thread with class operator().\n";
	m_name = "Class Call Operator example";
	m_id = m_counter++;
}

void CallExample::Run() {
	Call callObject;
	// !!: the object is copied to the thread
	std::thread callThread(callObject);
	callThread.join();
}