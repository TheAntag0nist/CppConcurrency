#include <examples/MoveExample.h>

ScopedThread::ScopedThread(std::thread t) : m_thread(std::move(t)) {
	if (t.joinable())
		throw std::logic_error("No threads");
}

ScopedThread::~ScopedThread() {
	if (m_thread.joinable())
		m_thread.join();
}

MoveExample::MoveExample() {
	m_id = m_counter++;
	m_name = "Move Threads Semantics Example";
	m_description = "Example that demonstrate how to works"
		"move semantics for threads.";
}

void MoveExample::Run() {
	int localVariable = 0;
	ScopedThread newScopedThread(
		std::thread{ 
			Func(localVariable) 
		}
	);
	// Do something in current thread
	for (int iter = 0; iter < 10; ++iter)
		std::cout << "[MAIN_THREAD]:> Work immitation\n";
}