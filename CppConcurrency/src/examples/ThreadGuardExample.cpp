#include <examples/ThreadGuardExample.h>

ThreadGuard::ThreadGuard(std::thread& t) : m_thread(t) { }

ThreadGuard::~ThreadGuard() { 
	if (m_thread.joinable()) {
		m_thread.join(); 
		std::cout << "[ThreadGuard]:> Thread was joined\n";
	}
}

ThreadGuardExample::ThreadGuardExample() {
	m_id = m_counter++;
	m_name = "Thread Guard Example";
	m_description = "Safe Thread execution with exceptions";
}

void ThreadGuardExample::Run() {
	int localVariable = 1;
	std::thread test(
		[localVariable]() {
			for (int i = 0; i < 50; ++i) {
				std::cout << "ID: " << localVariable << " -> Thread with thread guard.\n";
				std::cout << "Iter: " << i << std::endl;
			}
		}
	);

	ThreadGuard threadGuard(test);
	std::cout << "Next step it's Fake Exception\n";
	throw std::exception();
}