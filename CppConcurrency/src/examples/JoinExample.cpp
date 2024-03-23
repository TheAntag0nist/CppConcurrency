#include <examples/JoinExample.h>

JoinExample::JoinExample() {
	m_description = "This is an 'Example of Join'."
		"It demonstrates how to properly combine a"
		"thread with exception handling";
	m_name = "Exception Safe Join example";
	m_id = m_counter++;
}

void JoinExample::Run() {
	int localVariableID = 5;
	Func func(localVariableID);
	std::thread test{func};

	try {
		// some actions in main thread
		for (int iter = 0; iter < 200; ++iter) {
			std::cout << "Main Thread: " << iter << std::endl;
			if (iter == 150)
				throw std::exception();
		}
	}
	catch (std::exception& ex) {
		// Guarantee that the thread will end before exiting the function
		test.join();
		throw;
	}

	test.join();
}