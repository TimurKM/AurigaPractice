#pragma once
#include <string>

class Ticket
{
private:
	std::string m_destination;

	size_t m_flight = 0;

	std::string m_fio;

	std::string m_date;
public:
	Ticket(const std::string& destination, size_t flight, const std::string& fio, const std::string& date);

	friend std::ostream& operator<< (std::ostream& out, const Ticket& ticket);

	friend bool operator==(const Ticket& ticket1, const Ticket& ticket2);

	friend bool operator!=(const Ticket& ticket1, const Ticket& ticket2);
};
