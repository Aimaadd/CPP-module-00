#include "Phonebook.hpp"

static int hasSpaces(std::string str) {
    int i = 0;

    while (str[i]) {
        if (isspace(str[i]) == 0)
            return 0;
        i++;
    }
    if (str[i] == '\0')
        return 1;
    return 0;
}

std::string    Phonebook::setString(const std::string &prompt) {
    std::string input;
    do {
        std::cout << prompt << std::endl;
        getline(std::cin, input);
        if (input == "\0")
			exit(1);
    } while (input.empty() || hasSpaces(input) == 1);
    return input;
}