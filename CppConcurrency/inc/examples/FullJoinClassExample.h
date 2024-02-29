#ifndef JOINING_THREAD_H
#define JOINING_THREAD_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <core/Func.h>
#include <stdafx.h>

class JoiningThread {
protected:
	std::thread m_thread;
public:
	JoiningThread() noexcept = default;

	template <typename Callable, typename ... Args>
	explicit JoiningThread(Callable&& func, Args&&... args) : 
		m_thread(std::forward<Callable>(func)), std::forward<Args>(args) ... {}

	explicit JoiningThread(std::thread t) noexcept :
		m_thread(std::move(t)) {}

	JoiningThread(JoiningThread&& joiningThread) noexcept :
		m_thread(std::move(joiningThread.m_thread)) {}

	JoiningThread& operator=(JoiningThread&& other) noexcept {
		if (m_thread.joinable())
			m_thread.join();
		m_thread = std::move(other.m_thread);
		return *this;
	}

	JoiningThread& operator=(std::thread other) noexcept {
		if (m_thread.joinable())
			m_thread.join();
		m_thread = std::move(other);
		return *this;
	}

	~JoiningThread() {
		if (m_thread.joinable())
			m_thread.join();
	}

	void Swap(JoiningThread& other) noexcept {
		m_thread.swap(other.m_thread);
	}

	std::thread::id GetId() const noexcept {
		return m_thread.get_id();
	}

	bool Joinable() const noexcept {
		return m_thread.joinable();
	}

	void Join() {
		m_thread.join();
	}

	void Detach() {
		m_thread.detach();
	}

	std::thread& AsThread() noexcept {
		return m_thread;
	}

	const std::thread& AsThread() const noexcept {
		return m_thread;
	}
};

class FullJoinClassExample : public Example, public Singleton<FullJoinClassExample> {
protected:
	FullJoinClassExample();
	friend Singleton<FullJoinClassExample>;

public:
	virtual ~FullJoinClassExample() = default;
	virtual void Run() override;
};

#endif