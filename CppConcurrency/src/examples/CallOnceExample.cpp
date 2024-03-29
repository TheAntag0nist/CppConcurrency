#include <examples/CallOnceExample.h>

void InitSomeResource(std::shared_ptr<SomeResource>& resource) {
	resource.reset(new SomeResource());
	std::cout << "[INF]:> Init SomeResource\n";
}

CallOnceExample::CallOnceExample() {
	m_id = m_counter++;
	m_name = "Example with call_once";
	m_description = "It's example with std::call_once and std::once_flag.\n"
		"Despite the presence of two threads, the function will be called once.\n" 
		"Can be used to initialize shared resources\n";
}

void CallOnceExample::Run() {
	std::shared_ptr<SomeResource> resourcePtr;
	std::once_flag resourceCreationFlag;

	auto func = [&resourceCreationFlag](std::shared_ptr<SomeResource>& res) {
		std::call_once(resourceCreationFlag, &InitSomeResource, res);
		// do something
	};
	
	std::thread first(
		func,
		std::ref(resourcePtr)
	);
	std::thread second(
		func,
		std::ref(resourcePtr)
	);

	second.join();
	first.join();
}