#ifndef UNIQUE_LOCK_UNLOCK_H
#define UNIQUE_LOCK_UNLOCK_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <stdafx.h>

class Resource {
private:
	std::vector<int> m_data;
	std::mutex m_mutex;

public:
	~Resource() {}
	Resource() = delete;
	Resource(size_t size, int startValue, int step) {
		m_data.resize(size);
		for (int i = 0; i < size; ++i)
			m_data[i] = startValue + step * i;
	}
	
	std::mutex& GetMutex() { return m_mutex; }
	size_t GetDataSize() { return m_data.size(); }
	
	int ReadValue(int id) { return m_data[id]; }
	void WriteValue(int id, int value) { m_data[id] = value; }
};

class UniqueLockUnlockExample : public Example, public Singleton<UniqueLockUnlockExample> {
protected:
	friend Singleton<UniqueLockUnlockExample>;
	UniqueLockUnlockExample();

public:
	virtual ~UniqueLockUnlockExample() = default;
	virtual void Run() override;
};

#endif