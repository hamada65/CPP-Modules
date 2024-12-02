#include <iostream>
#include <iomanip>
#include <limits>
#include <ios>
#include <sstream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactNB(0), contactIndex(0) {}

std::string Contact::getFName() const { return fName; }
void Contact::setFName(const std::string &fName) { this->fName = fName; }

std::string Contact::getLName() const { return lName; }
void Contact::setLName(const std::string &lName) { this->lName = lName; }

std::string Contact::getNName() const { return nName; }
void Contact::setNName(const std::string &nName) { this->nName = nName; }

std::string Contact::getPNumber() const { return pNumber; }
void Contact::setPNumber(const std::string &pNumber) { this->pNumber = pNumber; }

std::string Contact::getDarkestSecret() const { return darkestSecret; }
void Contact::setDarkestSecret(const std::string &darkestSecret) { this->darkestSecret = darkestSecret; }

bool getInput(std::string &input) {
  std::getline(std::cin, input);
  return std::cin.eof();
}

int PhoneBook::ADD()
{
    std::string input;
    std::cout << "First Name : ";
    if (getInput(input))
        return 1;
    Contacts[contactIndex].setFName(input);
    std::cout << "Last Name : ";
    if (getInput(input))
        return 1;
    Contacts[contactIndex].setLName(input);
    std::cout << "Nickname : ";
    if (getInput(input))
        return 1;
    Contacts[contactIndex].setNName(input);
    std::cout << "Phone Number : ";
    if (getInput(input))
        return 1;
    Contacts[contactIndex].setPNumber(input);
    std::cout << "Darkest Secret : ";
    if (getInput(input))
        return 1;
    Contacts[contactIndex].setDarkestSecret(input);
    if (contactNB < 8)
        contactNB++;
    contactIndex++;
    if (contactIndex == 8)
        contactIndex = 0;
    std::cout << "Contact added !" << std::endl;
    return 0;
}

int PhoneBook::SEARCH()
{
    if (contactNB == 0)
        std::cout << "PhoneBook is empty !" << std::endl;
    else
    {
        std::cout << " ___________________________________________ " << std::endl;
        std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
        std::cout << "|----------|----------|----------|----------|" << std::endl;
        for (int i = 0; i < contactNB; i++)
        {
            std::cout << "|         " << i << "|";
            if (Contacts[i].getFName().length() > 10)
                std::cout << Contacts[i].getFName().substr(0, 9) << ".|";
            else
                std::cout << std::setw(10) << Contacts[i].getFName() << "|";
            if (Contacts[i].getLName().length() > 10)
                std::cout<< Contacts[i].getLName().substr(0, 9) << ".|";
            else
                std::cout << std::setw(10) << Contacts[i].getLName() << "|";
            if (Contacts[i].getNName().length() > 10)
                std::cout<< Contacts[i].getNName().substr(0, 9) << ".|";
            else
                std::cout << std::setw(10) << Contacts[i].getNName() << "|";
            std::cout << std::endl;
        }
        std::cout << " ------------------------------------------- " << std::endl;
        std::cout << "Enter index of the contact you want to see : " << std::endl;
        int index;
        std::string indexInput;
        if (getInput(indexInput))
            return 1;
        std::stringstream ss(indexInput);
        std::string trash;
        if (!(ss >> index))
        {
            std::cerr << "INDEX ERROR !" << std::endl;
            return 0;
        }
        if (ss >> trash)
        {
            std::cerr << "INDEX ERROR !" << std::endl;
            return 0;
        }
        if (index >= 0 && index < contactNB)
        {
            std::cout << "First Name : " << Contacts[index].getFName() << "\n";
            std::cout << "Last Name : " << Contacts[index].getLName() << "\n";
            std::cout << "Nickname : " << Contacts[index].getNName() << "\n";
            std::cout << "Phone Number : " << Contacts[index].getPNumber() << "\n";
            std::cout << "Darkest Secret : " << Contacts[index].getDarkestSecret() << std::endl;
        }
        else
            std::cerr << "INDEX NOT FOUND !" << std::endl;
    }
    return 0;
}

int PhoneBook::EXIT()
{
    std::cout << "Exiting PhoneBook !" << std::endl;
    return 1;
}

int PhoneBook::ExecuteCommand(std::string command) {
    if (command == "ADD")
        return ADD();
    else if (command == "SEARCH")
        return SEARCH();
    else if (command == "EXIT")
        return EXIT();
    std::cout << "INVALID COMMAND !" << std::endl;
    return 0;
}

int main() {
    PhoneBook Book;
    std::string Command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, or EXIT): ";
        if (getInput(Command))
            break;
        if (Book.ExecuteCommand(Command))
            break;
    }
    return 0;
}