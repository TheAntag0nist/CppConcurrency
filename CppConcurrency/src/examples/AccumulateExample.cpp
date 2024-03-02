#include <examples/AccumulateExample.h>

template <typename Iterator, typename T>
T AccumulateExample::Accumulate(Iterator first, Iterator last, T init) {
	return std::accumulate(first, last, init);
}

template <typename Iterator, typename T>
T AccumulateExample::ParallelAccumulate(Iterator first, Iterator last, T init) {
	auto length = std::distance(first, last);
	if (!length)
		return init;

	const uint32_t minChunkSize = 25;
	const uint32_t calculatedNumThreads = (length + minChunkSize - 1) / minChunkSize;
	const uint32_t numHardwareThreads = std::thread::hardware_concurrency();

	uint32_t numThreads = std::min(
		numHardwareThreads != 0 ? numHardwareThreads : 2,
		calculatedNumThreads
	);

	std::vector<std::thread> accThreads(numThreads - 1);
	std::vector<T> results(numThreads);

	const uint32_t blockSize = length / numThreads;
	Iterator blockStart = first;
	
	for (uint32_t i = 0; i < numThreads - 1; ++i) {
		Iterator blockEnd = blockStart;
		std::advance(blockEnd, blockSize);

		accThreads[i] = std::thread{
			AccumulateBlock<Iterator,T>(),
			blockStart, blockEnd, std::ref(results[i])
		};
		blockStart = blockEnd;
	}
	AccumulateBlock<Iterator, T>()(
		blockStart, last, 
		results[numThreads - 1]
	);

	for (auto& item : accThreads)
		item.join();

	return std::accumulate(results.begin(), results.end(), init);
}


AccumulateExample::AccumulateExample() {
	m_id = m_counter++;
	m_name = "Accumulator Example";
	m_description = "It's example of simple accumulator function";
}

void AccumulateExample::Run() {
	std::vector<uint32_t> values(50'000'000, 10);
	uint32_t init = 5;

	auto startTime = std::chrono::high_resolution_clock::now();
	uint32_t result = Accumulate<std::vector<uint32_t>::iterator, uint32_t>
		(values.begin(), values.end(), init);
	auto endTime = std::chrono::high_resolution_clock::now();
	auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

	auto startTimeParallel = std::chrono::high_resolution_clock::now();
	uint32_t parallelResult = ParallelAccumulate<std::vector<uint32_t>::iterator, uint32_t>
		(values.begin(), values.end(), init);
	auto endTimeParallel = std::chrono::high_resolution_clock::now();
	auto deltaParallel = std::chrono::duration_cast<std::chrono::milliseconds>(endTimeParallel - startTimeParallel);

	std::cout << "[LOG]:> Normal Result: " << result << std::endl;
	std::cout << "[LOG]:> Normal Time: " << delta.count() << "ms\n";
	std::cout << "[LOG]:> Parallel Result: " << parallelResult << std::endl;
	std::cout << "[LOG]:> Parallel Time: " << deltaParallel.count() << "ms\n";
}