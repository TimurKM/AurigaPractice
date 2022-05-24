#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <memory>
#include "Ticket.h"
#include "TicketsList.h"

//static std::unique_ptr<Ticket> getUserTicketInput();
static Ticket getUserTicketInput();
static int getUserChoice();

int main()
{
	auto tickets = std::make_unique<TicketsList>();

	tickets->addTicket({ "Moscow", 1, "AAA", "01-01-2022" });
	tickets->addTicket({ "Moscow", 2, "BBB", "02-02-2022" });
	tickets->addTicket({ "Moscow", 3, "CCC", "03-03-2022" });

	if (tickets != nullptr)
	{
		auto userChoice = getUserChoice();

		if (userChoice == 2)
		{
			auto ticket = getUserTicketInput();

			tickets->addTicket(ticket);
		}
		else if (userChoice == 3)
		{
			auto ticketToDelete = getUserTicketInput();

			tickets->deleteTicket(ticketToDelete);
		}

		std::cout << *tickets << std::endl;
	}

	return 0;
}

int getUserChoice()
{
	auto userChoice = 0;

	do
	{
		std::cout << "Input 1 (printList) or 2 (addTicket) or 3 (deleteTicket): " << std::endl;

		std::cin >> userChoice;
	} while (userChoice != 1 && userChoice != 2 && userChoice != 3);

	return userChoice;
}

//std::unique_ptr<Ticket> getUserTicketInput()
Ticket getUserTicketInput()
{
	std::string destination;

	int flight = 0;

	std::string fio;

	std::string date;

	while (1)
	{
		std::cout << "Enter destination: ";

		std::cin >> std::ws;

		getline(std::cin, destination);

		do
		{
			std::cout << "Enter flight: ";

			std::cin >> flight;
		} while (flight < 0);


		std::cout << "Enter fio: ";

		std::cin >> std::ws;

		getline(std::cin, fio);

		std::cout << "Enter date: ";

		std::cin >> std::ws;

		getline(std::cin, date);

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}

		break;
	}

	return Ticket(destination, flight, fio, date);

	//return std::make_unique<Ticket>(destination, flight, fio, date);
}