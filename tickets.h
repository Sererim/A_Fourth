#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cassert>


struct Ticket {
    double priceTicket;
    unsigned int place;
    int rootNumber;
    time_t dateTime;
    bool isValid;
    std::string description;
};


class TicketProvider{
public:
    static bool updateTicket(Ticket ticket)
    {
        std::cout << "Enter price of the ticket.\n";
        std::cin >> ticket.priceTicket;
        std::cout << "Enter place of the ticket.\n";
        std::cin >> ticket.place;
        std::cout << "Enter description of the ticket.\n";
        std::cin >> ticket.description;
        return true;
    }
    static Ticket getTicket(int rootNumber, std::vector<Ticket> tickets)
    {
        Ticket search_result;
        for (Ticket ticket : tickets)
        {
            if (ticket.rootNumber == rootNumber) search_result = ticket;
        }
        return search_result;
    }

    static void showTicket(int rootNumber, std::vector<Ticket> tickets)
    {
        Ticket search_result;
        for (Ticket ticket : tickets)
        {
            if (ticket.rootNumber == rootNumber)
            {
                std::cout << ticket.description << std::endl;
                std::cout << ticket.priceTicket << std::endl;
                std::cout << ticket.dateTime << std::endl;
            }
        }
    }
};

class Customer;

class cashProvider{
private:
    long card;
    bool isAuthorization;
    int amount;
public:
    cashProvider(long card, int amount){
        this -> card = card;
        this -> amount = amount;
        isAuthorization = true;
    }

    bool buy(int price){
        // Design by contract.
        assert(isAuthorization);
        assert(amount >= price);
        // Process payment
        amount -= price;
        return true;
    }

    bool autorization(Customer customer){
        // Perform authorization checks.
        return true;
    }

    void showBalance(){
        std::cout << "Amount: " << amount << "\n";
    }
};


class Customer{
private:
    int id;
    std::vector<Ticket> tickets;
    cashProvider cash;
public:
    Customer(int id, cashProvider cash, std::vector<Ticket> tickets){
        this -> id = id;
        this -> cash = cash;
        this -> tickets = tickets;
    }

    bool buyTicket(Ticket ticket)
    {
        // Design by contract.
        assert(ticket.isValid);
        assert(cash.buy(ticket.priceTicket));
        return true;
    }

    std::vector<Ticket> searchTicket(time_t date)
    {
        std::vector<Ticket> search_result;
        // Search tickets by date.
        return search_result;
    }

    std::vector<Ticket> searchTicket(std::string description)
    {
        std::vector<Ticket> search_result;
        // Search tickets by description.
        return search_result;
    }
};
