#include "Phonebook.hpp"
#include "Contact.hpp"
#include <string.h>


void signalHandler( int signum ) {
	std::cout << "Interrupt signal (" << signum << ") received.\n";
	exit(signum);
}

std::string formatField(const std::string &field) {
    if (field.length() > 10) {
        return field.substr(0, 9) + ".";
    }
    return field;
}

void searchContact(Phonebook book, int index) {
    std::cout << "| Index     | First na   | Last Nam   | Nickname   |" << std::endl;
    for (int j = 0; j < index; j++) {
        std::cout << "| " << std::setw(9) << j << " | ";
        std::cout << std::setw(10) << formatField(book.contact[j].first_name) << " | ";
        std::cout << std::setw(10) << formatField(book.contact[j].last_name) << " | ";
        std::cout << std::setw(10) << formatField(book.contact[j].nickname) << " | ";
        std::cout << std::endl;
    }
}

//check input et incremente index si tout est bon

void    fillField(Phonebook &book, int i) {
		std::string input;

	std::cout << "First Name :";
	book.contact[i].first_name = book.setString(input);
	std::cout << "Last Name :";
	book.contact[i].last_name = book.setString(input);
	std::cout << "Nickname :";
	book.contact[i].nickname = book.setString(input);
	std::cout << "Phone number :";
	book.contact[i].phone_number = book.setString(input);
	std::cout << "Secret :";
	book.contact[i].secret = book.setString(input);
	if (book.contact[i].secret.empty() ||
		book.contact[i].phone_number.empty() ||
		book.contact[i].nickname.empty() ||
		book.contact[i].last_name.empty() ||
		book.contact[i].first_name.empty()) {
		book.contact[i].~Contact();
		return;
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

	signal(SIGINT, signalHandler);
	std::cout << "\033[32m";
	std::cout << "Welcome to the phonebook user interface !" << std::endl;
	std::cout << "\033[0m";
	std::cout << "-----------------------------------------" << std::endl;
	prompt_function(book);
}