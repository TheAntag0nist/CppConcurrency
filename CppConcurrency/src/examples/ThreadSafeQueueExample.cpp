#include <examples/ThreadSafeQueueExample.h>

ThreadSafeQueueExample::ThreadSafeQueueExample() {
	m_id = m_counter++;
	m_name = "Thread Safe Queue Example";
	m_description = "It's example with thread safe queue implementation";
}

void ThreadSafeQueueExample::Run() {
	ThreadSafeQueue<double> safeQueue;
	const int size = 100;

	std::thread t1(
		[size](ThreadSafeQueue<double>& queue) {
			for (int i = 0; i < size; ++i) {
				std::stringstream ss;
				double newValue = i * 13.24f;
				ss << "[THREAD_1]:> Add new value -> " << newValue << std::endl;
				queue.Push(newValue);
				std::cout << ss.str();
			}
		},
		std::ref(safeQueue)
	);

	std::thread t2(
		[size](ThreadSafeQueue<double>& queue) {
			int i = 0;
			while (i < size) {
				std::stringstream ss;
				double value = 0.0f;
				
				queue.WaitAndPop(value);
				ss << "[THREAD_2]:> Read value = " << value << std::endl;
				std::cout << ss.str();
				++i;
			}
		},
		std::ref(safeQueue)
	);

	t2.join();
	t1.join();
}