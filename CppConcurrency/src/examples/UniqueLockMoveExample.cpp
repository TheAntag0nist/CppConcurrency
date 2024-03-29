#include <examples/UniqueLockMoveExample.h>

UniqueLockMoveExample::UniqueLockMoveExample() {
	m_id = m_counter++;
	m_name = "Move semantics for unique_lock";
	m_description = "Example with unique_lock move semantics. It's usefull when you Gateway Class.";
}

void UniqueLockMoveExample::Run() {
	std::unique_lock<std::mutex> lk(GetLock());
	// DoSomething();
	std::cout << "[INF]:> DoSomething()\n";
}

std::unique_lock<std::mutex> UniqueLockMoveExample::GetLock() {
	extern 	std::mutex mt;
	std::unique_lock<std::mutex> lk(mt);
	// some prepare data method
	std::cout << "[INF]:> PrepareData()\n";
	return lk;
}

std::mutex mt;
