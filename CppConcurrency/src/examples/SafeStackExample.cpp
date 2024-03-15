#include <examples/SafeStackExample.h>

SafeStackExample::SafeStackExample() {
	m_id = m_counter++;
	m_name = "Stack Thread Safe Example";
	m_description = "It's Thread Safe stack example for using without  race condition.";
}

void SafeStackExample::Run() {
	SafeStack<int> intStack;

	std::thread mainThread;
	std::thread otherThread;

	for(int i = 0; i < 10; ++i)
		intStack.Push(i);

	try {
		auto tempThread = std::thread(
			[](SafeStack<int>& s) {
				if (!s.Empty()) {
					int value = 0;
					s.Pop(value);
					std::cout << "[MAIN]:> value = " << value << std::endl;
				}
			},
			std::ref(intStack)
		);
		mainThread = std::move(tempThread);

		tempThread = std::thread(
			[](SafeStack<int>& s) {
				if (!s.Empty()) {
					auto valuePtr = s.Pop();
					std::cout << "[OTHER]:> value = " << *valuePtr << std::endl;
				}
			},
			std::ref(intStack)
		);
		otherThread = std::move(tempThread);
	}
	catch(std::exception& ex){
		std::cout << ex.what() << std::endl;
		if (mainThread.joinable())
			mainThread.join();
		if (otherThread.joinable())
			otherThread.join();
	}

	if (mainThread.joinable())
		mainThread.join();
	if (otherThread.joinable())
		otherThread.join();
}