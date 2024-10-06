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

void	phonebookPrompt(std::string &index) {

	while (1) {
		std::cout << "Enter contact index for detailed informations :" << std::endl;
		std::getline(std::cin, index);
		if (index == "\0")
			return ;
	}
}

void searchContact(Phonebook book, std::string index) {
    int ind = 0;
    if (!index.empty())
		ind = std::stoi(index);
	if (index.empty()) {
		while (ind < 7) {
		std::cout << "| Index     | First na   | Last Nam   | Nickname   |" << std::endl;
		std::cout << "| " << std::setw(9) << ind << " | ";
		std::cout << std::setw(10) << formatField(book.contact[ind].getFirstName()) << " | ";
		std::cout << std::setw(10) << formatField(book.contact[ind].getLastName()) << " | ";
		std::cout << std::setw(10) << formatField(book.contact[ind].getNickname()) << " | ";
		std::cout << std::endl;
		ind++;
		}
    }
	else if (ind >= 0 && ind < 8) {
			std::cout << "First Name : " << book.contact[ind].getFirstName() << std::endl;
			std::cout << "Last Name : " << book.contact[ind].getLastName() << std::endl;
			std::cout << "Nickname : " << book.contact[ind].getNickname() << std::endl;
			std::cout << "Phone number : " << book.contact[ind].getPhoneNumber() << std::endl;
			std::cout << "Secret : " << book.contact[ind].getSecret() << std::endl;
	}
}

void fillField(Phonebook &book, int i) {
    std::string input;

    std::cout << "First Name :";
    book.contact[i].setFirstName(book.setString(input));
    std::cout << "Last Name :";
    book.contact[i].setLastName(book.setString(input));
    std::cout << "Nickname :";
    book.contact[i].setNickname(book.setString(input));
    std::cout << "Phone number :";
    book.contact[i].setPhoneNumber(book.setString(input));
    std::cout << "Secret :";
    book.contact[i].setSecret(book.setString(input));

    if (book.contact[i].getSecret().empty() ||
        book.contact[i].getPhoneNumber().empty() ||
        book.contact[i].getNickname().empty() ||
        book.contact[i].getLastName().empty() ||
        book.contact[i].getFirstName().empty()) {
        book.contact[i].~Contact();
        return;
    }
}

void    prompt_function(Phonebook &book) {
	std::string input;
	std::string w;
	int i = 0;
	while (1) {
		std::cout << "Use a phonebook command from the manual :" << std::endl;
		std::getline(std::cin, input);
		if (input == "\0")
			return;
		if (input == "ADD")
		{
			if (i == 8)
				i = 0;
			fillField(book, i);
			i++;
		}
		else if (input == "SEARCH")
		{
			if (input == "\0")
				exit(1) ;
			std::cout << "Enter the index of the contact :" << std::endl;
			std::getline(std::cin, w);
			searchContact(book, w);
		}
		else if (input == "EXIT")
			exit(1);
		else
		{
			if (input == "\0")
				exit(1);
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