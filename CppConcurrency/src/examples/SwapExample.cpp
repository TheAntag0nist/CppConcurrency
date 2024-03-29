#include <examples/SwapExample.h>

SomeBigObject::SomeBigObject(size_t size) {
	m_data.resize(size);
}

void SomeBigObject::Swap(SomeBigObject& obj) {
	if (this == &obj)
		return;

	// #Var 1
	//std::lock(this->m_mutex, obj.m_mutex);
	//std::lock_guard<std::mutex> firstLock(this->m_mutex, std::adopt_lock);
	//std::lock_guard<std::mutex> secondLock(obj.m_mutex, std::adopt_lock);

	// #Var 2
	//std::scoped_lock lockAll(this->m_mutex,obj.m_mutex);

	// #Var 3
	std::unique_lock firstLock(this->m_mutex, std::defer_lock);
	std::unique_lock secondLock(obj.m_mutex, std::defer_lock);
	std::lock(firstLock, secondLock);

	this->m_data.swap(obj.m_data);
}

size_t SomeBigObject::GetSize() {
	return m_data.size();
}

SwapExample::SwapExample() {
	m_id = m_counter++;
	m_name = "Swap Two Objects Example";
	m_description = "Safe Swap two object without deadlock.";
}

void SwapExample::Run() {
	SomeBigObject first(10'000);
	SomeBigObject second(20'000);
	
	std::thread exampleThread;
	
	try {
		exampleThread = std::move(
			std::thread(
				[](SomeBigObject& obj1, SomeBigObject& obj2) {
					obj1.Swap(obj2);
				},
				std::ref(first),
				std::ref(second)
			)
		);
	}
	catch (std::exception& ex) {
		if (exampleThread.joinable())
			exampleThread.join();
	}

	if (exampleThread.joinable())
		exampleThread.join();

	std::cout << "[INF]:> first object size = " << first.GetSize() << std::endl;
	std::cout << "[INF]:> second object size = " << second.GetSize() << std::endl;
}