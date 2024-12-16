#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap " << name << " Created!" << std::endl;
    this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "ScavTrap " << name << " Created!" << std::endl;
    this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &source) : ClapTrap(source) {
    *this = source;
    std::cout << "ScavTrap " << name << " Created by copy!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " Destroyed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &source) {
    if (this == &source)
        return *this;

    ClapTrap::operator=(source);
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (HitPoints == 0)
    {
        std::cout << "ScavTrap" << name << "can't attack 💀" << std::endl;
        return;
    }
    if (EnergyPoints == 0)
    {
        std::cout << "ScavTrap" << name << "can't attack, no Energy Points left! 🪫" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage! 💥" << std::endl;
    EnergyPoints--;
}


void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " has entered in Gate keeper mode! 🚪" << std::endl;
}