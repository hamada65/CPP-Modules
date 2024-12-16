#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap " << name << " Created!" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "FragTrap " << name << " Created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &source) : ClapTrap(source) {
    *this = source;
    std::cout << "FragTrap " << name << " Created by copy!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " Destroyed!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &source) {
    if (this == &source)
        return *this;

    ClapTrap::operator=(source);
    return *this;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " says: \"High Five!\" 🖐️" << std::endl;
}