#include <examples/DnsCacheExample.h>

DnsCacheExample::DnsCacheExample() {
	m_id = m_counter++;
	m_name = "DNS Cache Example";
	m_description = "Example of a DNS cache with a low write frequency.";
}

void DnsCacheExample::Run() {
	std::vector<DnsEntry> entries = { DnsEntry("8.8.8.8"), DnsEntry("1.2.3.4"), DnsEntry("2.2.2.2") };
	std::vector<std::string> domains = { "dns-google.com", "dns-yandex.ru", "test-site.com"};
	DnsCache cache;

	// Fill data
	auto func = [&cache, &domains, &entries]() {
		for (int i = 0; i < entries.size(); ++i) {
			std::stringstream ss;
			ss << "[INF]:> Update or add entity" << std::endl;
			std::cout << ss.str();
			cache.UpdateOrAddEntry(domains[i], entries[i]);
		}
	};
	func();

	domains.push_back("fake-dns.com");
	entries.push_back(std::move(DnsEntry("4.3.2.1")));

	std::thread t1(func);
	std::thread t2(
		[&cache, &domains, &entries]() {
			for (int domainId = 0; domainId < domains.size(); ++domainId) {
				std::string domain = domains[domainId];
				DnsEntry entry = cache.FindEntry(domain);
				std::stringstream ss;
				ss << "[INF]:> DNS -> " << domain << " IP -> " << entry.GetIP() << std::endl;
				std::cout << ss.str();
			}
		}
	);

	t2.join();
	t1.join();
}