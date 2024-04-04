#include <examples/ConditionalVariableExample.h>

ConditionalVariableExample::ConditionalVariableExample() {
	m_id = m_counter++;
	m_name = "Example with std::condition_variable";
	m_description = "This is an example with a conditional variable,\n"
		"when one of the threads is waiting for data from the other.\n";
}

void ConditionalVariableExample::Run() {
	std::thread t1(
		&ConditionalVariableExample::DataPreparationThread, this
	);

	std::thread t2(
		&ConditionalVariableExample::DataProcessThread,
		this
	);

	t2.join();
	t1.join();
}


void ConditionalVariableExample::DataPreparationThread() {
	for (size_t id = 0; id < m_dataSize; ++id) {
		// Init chunk
		DataChunk chunk;
		chunk.data.resize(10);
		std::fill(chunk.data.begin(), chunk.data.end(), id);

		// Push chunk to queue
		{
			std::lock_guard<std::mutex> lk(m_mutex);
			m_chunks.push(chunk);
		}

		// Notify thread
		std::stringstream ss;
		ss << "[THREAD_1]:> data was added ID -> " << id << std::endl;
		std::cout << ss.str();
		m_condition.notify_one();
	}
}

void ConditionalVariableExample::DataProcessThread() {
	for (size_t itemId = 0; itemId < m_dataSize; ++itemId) {
		std::unique_lock<std::mutex> lk(m_mutex);
		m_condition.wait(lk, [this]() { return !m_chunks.empty(); });

		auto dataChunk = m_chunks.front();
		m_chunks.pop();
		std::cout << "[THREAD_2]:> data was readed;\n";
		lk.unlock();

		// process data
		std::stringstream ss;
		ss << "ID -> " << itemId << std::endl;
		for (size_t id = 0; id < dataChunk.data.size(); ++id)
			ss << "data[" << id << "] = " << dataChunk.data[id] << std::endl;
		std::cout << ss.str();
	}
}