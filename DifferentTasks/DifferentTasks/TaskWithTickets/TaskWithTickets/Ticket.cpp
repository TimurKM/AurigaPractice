#include "Ticket.h"
#include <iostream>

Ticket::Ticket(const std::string& destination, size_t flight, const std::string& fio, const std::string& date) :
	m_destination(destination), m_flight(flight), m_fio(fio), m_date(date)
{

}

std::ostream& operator<< (std::ostream& out, const Ticket& ticket)
{
	out << ticket.m_destination << " " << ticket.m_flight << " " << ticket.m_fio << " " << ticket.m_date << std::endl;

	return out;
}

bool operator==(const Ticket& ticket1, const Ticket& ticket2)
{
	return ticket1.m_destination == ticket2.m_destination && ticket1.m_flight == ticket2.m_flight && ticket1.m_fio == ticket2.m_fio && ticket1.m_date == ticket2.m_date;
}

bool operator!=(const Ticket& ticket1, const Ticket& ticket2)
{
	return !operator==(ticket1, ticket2);
}