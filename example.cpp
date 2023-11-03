#include "tickets.h"

int main() {
    // Create a ticket provider instance
    TicketProvider ticketProvider;

    // Create a cash provider instance
    cashProvider cash(123456789, 500);

    // Update a ticket
    Ticket ticket;
    ticket.priceTicket = 20.0;
    ticket.place = 1;
    ticket.description = "Concert Ticket";
    TicketProvider::updateTicket(ticket);

    // Get a ticket
    int rootNumber = 10;
    std::vector<Ticket> tickets;
    Ticket ticketResult = TicketProvider::getTicket(rootNumber, tickets);

    // Show a ticket
    TicketProvider::showTicket(rootNumber, tickets);

    // Create a customer
    Customer customer(1, cash, tickets);

    // Buy a ticket
    if (cash.autorization(customer)) {
        if (ticketResult.isValid) {
            bool success = customer.buyTicket(ticketResult);
            if (success) {
                std::cout << "Ticket purchased successfully!" << std::endl;
            } else {
                std::cout << "Ticket purchase failed." << std::endl;
            }
        } else {
            std::cout << "Ticket is not valid." << std::endl;
        }
    }

    // Search tickets by date
    time_t date = std::time(nullptr);
    std::vector<Ticket> searchResults = customer.searchTicket(date);

    // Search tickets by description
    std::string description = "Festival";
    std::vector<Ticket> searchResults2 = customer.searchTicket(description);

    // Show cash balance
    cash.showBalance();

    return 0;
}
