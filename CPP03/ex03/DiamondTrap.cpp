#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), name("Default") {
    std::cout << "DiamondTrap " << ClapTrap::name << " Created!" << std::endl;
    this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 30;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name+"_clap_name"), name(name) {
    std::cout << "DiamondTrap " << ClapTrap::name << " Created!" << std::endl;
    this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &source) : ClapTrap(source), ScavTrap(source), FragTrap(source) {
    *this = source;
    std::cout << "DiamondTrap " << ClapTrap::name << " Created by copy!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << ClapTrap::name << " Destroyed!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &source) {
    if (this == &source)
        return *this;

    ClapTrap::operator=(source);
    name = source.name;
    return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap " << ClapTrap::name << " says: \"I am " << name << ", and I am a DiamondTrap!\" 💎" << std::endl;
}