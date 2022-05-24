#include "TicketsList.h"

size_t TicketsList::getSize()
{
	return m_tickets.size();
}

void TicketsList::addTicket(const Ticket& ticket)
{
	m_tickets.push_back(ticket);
}

void TicketsList::deleteTicket(const Ticket& ticket)
{
	std::erase_if(m_tickets, [&](const auto& element) { return ticket == element; });
}

std::ostream& operator<< (std::ostream& out, const TicketsList& ticketslist)
{
	for (const auto& element : ticketslist.m_tickets)
	{
		out << element;
	}

	return out;
}