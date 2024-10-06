#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

std::string Contact::getFirstName() const {
    return first_name;
}

std::string Contact::getLastName() const {
    return last_name;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phone_number;
}

std::string Contact::getSecret() const {
    return secret;
}

void Contact::setFirstName(const std::string &firstName) {
    this->first_name = firstName;
}

void Contact::setLastName(const std::string &lastName) {
    this->last_name = lastName;
}

void Contact::setNickname(const std::string &nickname) {
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
    this->phone_number = phoneNumber;
}

void Contact::setSecret(const std::string &secret) {
    this->secret = secret;
}

void Contact::displayContact() const {
    std::cout << "First Name : " << first_name << std::endl;
    std::cout << "Last Name : " << last_name << std::endl;
    std::cout << "Nickname : " << nickname << std::endl;
    std::cout << "Phone number : " << phone_number << std::endl;
    std::cout << "Secret : " << secret << std::endl;
}