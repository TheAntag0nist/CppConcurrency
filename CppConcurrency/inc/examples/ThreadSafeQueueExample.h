#ifndef THREAD_SAFE_QUEUE_EXAMPLE_H
#define THREAD_SAFE_QUEUE_EXAMPLE_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <stdafx.h>

template <typename T>
class ThreadSafeQueue {
protected:
	std::condition_variable m_condVar;
	std::queue<T> m_data;
	std::mutex m_mutex;

public:
	ThreadSafeQueue() {}
	ThreadSafeQueue(const ThreadSafeQueue& queue) {}
	ThreadSafeQueue& operator=(const ThreadSafeQueue& obj) = delete;
	virtual ~ThreadSafeQueue() {}

	void Push(T value) {
		std::scoped_lock<std::mutex> lk(m_mutex);
		m_data.push(value);
		m_condVar.notify_one();
	}

	bool TryPop(T& res) {
		std::scoped_lock<std::mutex> lk(m_mutex);
		if (m_data.empty())
			return;
		res = m_data.front();
		m_data.pop();
	}

	void WaitAndPop(T& res) {
		std::unique_lock<std::mutex> lk(m_mutex);
		m_condVar.wait(lk, [this] { return !m_data.empty(); });
		res = m_data.front();
		m_data.pop();
	}

	std::shared_ptr<T> TryPop() {
		std::scoped_lock<std::mutex> lk(m_mutex);
		if (m_data.empty())
			return std::shared_ptr<T>();
		std::shared_ptr<T> res(std::make_shared<T>(m_data.front()));
		m_data.pop();
		return res;
	}

	size_t Size() {
		std::scoped_lock<std::mutex> lk(m_mutex);
		return m_data.size();
	}

	bool Empty() const {
		std::scoped_lock<std::mutex> lk(std::remove_const<std::mutex>(m_mutex));
		return m_data.empty();
	}
};

class ThreadSafeQueueExample : public Example, public Singleton<ThreadSafeQueueExample> {
protected:
	ThreadSafeQueueExample();
	friend Singleton<ThreadSafeQueueExample>;

public:
	virtual ~ThreadSafeQueueExample() = default;
	virtual void Run() override;
};

#endif