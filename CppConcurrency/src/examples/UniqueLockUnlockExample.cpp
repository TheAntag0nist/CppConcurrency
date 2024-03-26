#include <examples/UniqueLockUnlockExample.h>

UniqueLockUnlockExample::UniqueLockUnlockExample() {
	m_id = m_counter++;
	m_name = "Lock/Unlock unique_lock";
	m_description = "Example with unique_lock lock/unlock.\n" 
		"This is useful when you need it so that the thread\n"
		"frees up the resource during data processing.";
}

void UniqueLockUnlockExample::Run() {
	Resource exampleResource(100, -50, 1);

	auto func = [](Resource& res) {
		std::unique_lock<std::mutex> lk(res.GetMutex());
		size_t size = res.GetDataSize();
		std::stringstream ss;

		std::vector<int> newVectorData;
		newVectorData.resize(size);

		for (int i = 0; i < size; ++i) {
			int value = res.ReadValue(i);
			newVectorData[i] = value;
		}

		lk.unlock();
		for (int i = 0; i < size; ++i) {
			newVectorData[i] += 10;
			// !!: It's important for normal output
			// Intresting behaviour if not create string with stringstream and just pass data to std::cout stream 
			ss << "[THREAD_" << std::this_thread::get_id() << "]:> value = " << newVectorData[i] << std::endl;
			std::cout << ss.str();
		}

		lk.lock();
		for (int i = 0; i < size; ++i)
			res.WriteValue(i, newVectorData[i]);
	};

	std::thread fisrtThread(
		func,
		std::ref(exampleResource)
	);
	std::thread secondThread(
		func,
		std::ref(exampleResource)
	);

	fisrtThread.join();
	secondThread.join();
}