#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
    public :
        Contact();
        ~Contact();
        std::string getFirstName() const;
        void setFirstName(const std::string &firstName);
        std::string getLastName() const;
        void setLastName(const std::string &lastName);
        std::string getNickname() const;
        void setNickname(const std::string &nickname);
        std::string getPhoneNumber() const;
        void setPhoneNumber(const std::string &phoneNumber);
        std::string getSecret() const;
        void setSecret(const std::string &secret);
        void displayContact() const;
    private :
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string secret;
};

#endif