#ifndef SAFE_STACK_H
#define SAFE_STACK_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <stdafx.h>

class EmptyStack : public std::exception{
public:
	EmptyStack() {}
	virtual ~EmptyStack() {}
	const char* what() const throw() {
		return "[EX]:> Empty stack";
	}
};

template <class T>
class SafeStack {
private:
	std::stack<T> m_stack;
	std::mutex m_mutex;
public:
	SafeStack() {}
	SafeStack(const SafeStack& stack) {
		std::scoped_lock lock(m_mutex);
		m_stack = stack.m_stack;
	}

	virtual ~SafeStack() = default;
	SafeStack& operator=(SafeStack& stack) = delete;
	
	void Push(T value) {
		std::scoped_lock lock(m_mutex);
		m_stack.push(value);
	}
	
	bool Empty() {
		std::scoped_lock lock(m_mutex);
		return m_stack.empty();
	}
	
	std::shared_ptr<T> Pop() {
		std::scoped_lock lock(m_mutex);
		if (m_stack.empty())
			throw EmptyStack();
		const std::shared_ptr<T> result(std::make_shared<T>(m_stack.top()));
		m_stack.pop();
		return result;
	}

	void Pop(T& value) {
		std::scoped_lock lock(m_mutex);
		if (m_stack.empty()) 
			throw EmptyStack();
		value = m_stack.top();
		m_stack.pop();
	}
};

class SafeStackExample : public Example, public Singleton<SafeStackExample> {
protected:
	SafeStackExample();
	friend Singleton<SafeStackExample>;

public:
	virtual ~SafeStackExample() = default;
	virtual void Run() override;
};

#endif