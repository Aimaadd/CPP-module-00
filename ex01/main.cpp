#include "Phonebook.hpp"
#include "Contact.hpp"
#include <string.h>


void    searchContact(Phonebook book, int index) {
    std::cout << "| Index    | First na | Last Nam | Nickname |" << std::endl;
    for (int j = 0; j < index; j++) {
        std::cout << "   " <<j << "          ";
        std::cout << std::setw(10) << book.contact[j].first_name << " ";
        std::cout << std::setw(10) << book.contact[j].last_name << " ";
        std::cout << std::setw(10) << book.contact[j].nickname << " ";
        std::cout << std::endl;
    }
}

//check input et incremente index si tout est bon

void    fillField(Phonebook &book, int i) {
    {
        std::string test;

        while (test.empty()) {
            std::cout << "First Name :" << std::endl;
            getline(std::cin, test);
        }
        book.contact[i].first_name = book.setString(test);
        std::cout << "Last Name :" << std::endl;
        book.contact[i].last_name = book.setString();
        std::cout << "Nickname :" << std::endl;
        book.contact[i].nickname = book.setString();
        std::cout << "Phone Number :" << std::endl;
        book.contact[i].phone_number = book.setString();
        std::cout << "Secret :" << std::endl;
        book.contact[i].secret = book.setString();
        if (book.contact[i].secret.length() == 0
            || book.contact[i].phone_number.length() == 0
            || book.contact[i].nickname.length() == 0
            || book.contact[i].last_name.length() == 0
            || book.contact[i].first_name.length() == 0)
        {
            std::cout << "HERE !" << std::endl;
            book.contact[i].~Contact();
            return ;
        }    
    }
}

void    prompt_function(Phonebook &book) {
    std::string input;
    int i = 0;
    while (1) {
        std::cout << "Use a phonebook command from the manual :" << std::endl;
        std::getline(std::cin, input);
        if (input == "ADD")
        {
            fillField(book, i); //int ou bool pour refaire le contact
            i++;
        }
        else if (input == "SEARCH")
            searchContact(book, i);
        else if (input == "EXIT")
            exit(1);
        else
        {
            std::cout << "\033[31m";
            std::cout << "Wrong command or no command entered" << std::endl;
            std::cout << "\033[0m";
            std::cout << "-----------------------------------------" << std::endl;
        }
    } 
}

int main() {
    Phonebook book;

    std::cout << "\033[32m";
    std::cout << "Welcome to the phonebook user interface !" << std::endl;
    std::cout << "\033[0m";
    std::cout << "-----------------------------------------" << std::endl;
    prompt_function(book);
}