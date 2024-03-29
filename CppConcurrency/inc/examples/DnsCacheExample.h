#ifndef DNS_CACHE_EXAMPLE_H
#define DNS_CACHE_EXAMPLE_H
#include <core/Singleton.h>
#include <core/Example.h>
#include <stdafx.h>

class DnsEntry {
public:
	DnsEntry() : m_ip("Not found") {}
	DnsEntry(const DnsEntry& other) {
		if (this != &other) {
			std::unique_lock<std::mutex> lkThis(this->m_mutex, std::defer_lock);
			std::unique_lock<std::mutex> lkOther(other.m_mutex, std::defer_lock);
			std::lock(lkThis, lkOther);
			this->m_ip = other.m_ip;
		}
	}
	DnsEntry(std::string ip) : m_ip(ip) {}

	std::string GetIP() {
		std::lock_guard<std::mutex> lk(m_mutex);
		return m_ip;
	}

	DnsEntry operator=(DnsEntry& other) {
		if (this != &other) {
			std::unique_lock<std::mutex> mylock(m_mutex, std::defer_lock);
			std::unique_lock<std::mutex> otherlock(other.m_mutex, std::defer_lock);
			std::lock(mylock, otherlock);
			m_ip = other.m_ip;
		}
		return *this;
	}

private:
	mutable std::mutex m_mutex;
	std::string m_ip;
};

class DnsCache {
protected:
	std::map<std::string, DnsEntry> m_dnsCache;
	mutable std::shared_mutex m_entrytMutex;

public:
	DnsEntry FindEntry(std::string domain) {
		std::shared_lock<std::shared_mutex> lk(m_entrytMutex);
		if (m_dnsCache.find(domain) != m_dnsCache.end())
			return m_dnsCache[domain];
		return DnsEntry();
	}

	void UpdateOrAddEntry(std::string domain, DnsEntry entry) {
		std::lock_guard<std::shared_mutex> lk(m_entrytMutex);
		m_dnsCache[domain] = entry;
	}
};

class DnsCacheExample : public Example, public Singleton<DnsCacheExample> {
protected:
	DnsCacheExample();
	friend Singleton<DnsCacheExample>;

public:
	virtual ~DnsCacheExample() = default;
	virtual void Run() override;
};

#endif