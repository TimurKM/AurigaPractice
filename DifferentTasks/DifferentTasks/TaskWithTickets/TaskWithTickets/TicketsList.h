#pragma once
#include "Ticket.h"
#include <list>

class TicketsList
{
private:
	std::list<Ticket> m_tickets;
public:
	TicketsList() = default;

	size_t getSize();

	void addTicket(const Ticket& ticket);

	void deleteTicket(const Ticket& ticket);

	friend std::ostream& operator<< (std::ostream& out, const TicketsList& ticketslist);
};
