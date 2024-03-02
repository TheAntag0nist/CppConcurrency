#include <examples/MutexExample.h>


MutexExample::MutexExample() {
	m_id = m_counter++;
	m_name = "Mutex & LockGuard Example";
	m_description = "It's example of mutex and lock_guard using.";
}

void MutexExample::Run() {
	std::vector<std::thread> finders(4);
	std::vector<std::thread> adders(4);
	size_t fullSize = finders.size() + adders.size();
	size_t findCnt = 0;
	size_t addCnt = 0;

	for (int iter = 0; iter < fullSize; ++iter) {
		if (iter & 1)
			finders[findCnt++] = std::thread(&MutexExample::ListContains, this, iter - 1);
		else
			adders[addCnt++] = std::thread(&MutexExample::AddToList, this, iter);
	}

	findCnt = 0;
	addCnt = 0;

	for (int iter = 0; iter < fullSize; ++iter) {
		if (iter & 1)
			finders[findCnt++].join();
		else
			adders[addCnt++].join();
	}
}


void MutexExample::AddToList(uint32_t value) {
	std::scoped_lock guard(m_mutex);
	std::cout << "[ADDER]:> Add value to list -> " << value << std::endl;
	someList.push_back(value);
}

bool MutexExample::ListContains(uint32_t value) {
	std::scoped_lock guard(m_mutex);
	std::cout << "[FINDER]:> Find value in list -> " << value << std::endl;
	return std::find(someList.begin(), someList.end(), value) != someList.end();
}