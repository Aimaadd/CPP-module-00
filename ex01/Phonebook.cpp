#include "Phonebook.hpp"

std::string    Phonebook::setString()
{
    std::string input;
    getline(std::cin, input);
    if (input.empty())
        return "eartte";
    return input;
}