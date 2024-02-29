#include <examples/DetachExample.h>

DetachExample::DetachExample() {
	m_id = m_counter++;
	m_name = "Detach Thread Example";
	m_description = "Example with demon-thread that"
		"was detached from main thread.";
}

void DetachExample::Run() {
	std::thread test(
		[]() {
			for (int iter = 0; iter < 50; ++iter) {
				std::cout << "[DEMON_THREAD]:> Demon thread\n";
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
			}
		}
	);
	test.detach();

	for (int iter = 0; iter < 50; ++iter) {
		std::cout << "[MAIN_THREAD]:> Main thread\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}