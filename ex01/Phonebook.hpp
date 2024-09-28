#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <csignal>
#include <fstream>
#include "Contact.hpp"

class Phonebook {
    public :
        Contact contact[7];
        
        std::string setString(const std::string &prompt);
};

#endif