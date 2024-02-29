#include <examples/FullJoinClassExample.h>

FullJoinClassExample::FullJoinClassExample() {
	m_id = m_counter++;
	m_name = "Full Implementation JoinThread class";
	m_description = "It's example with fully implemented"
		"JoiningThread class";
}

void FullJoinClassExample::Run() {
	int firstVariable = 0; 
	int secondVariable = 1;
	int thirdVariable = 2;
	JoiningThread firstThread{ Func(firstVariable) };
	JoiningThread secondThread{ Func(secondVariable) };
	JoiningThread thirdThread{ Func(thirdVariable) };

	firstThread.Swap(secondThread);
	firstThread.Detach();

	bool isJoinable = secondThread.Joinable();
	std::cout << "[MAIN_THREAD]:> Is secondThread var joinable = " 
		<< isJoinable << std::endl;
	if (isJoinable)
		secondThread.Join();
}