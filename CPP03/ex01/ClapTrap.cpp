#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), HitPoints(100), EnergyPoints(50), AttackDamage(20) {
    std::cout << "ClapTrap " << name << " Created!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), HitPoints(100), EnergyPoints(50), AttackDamage(20) {
    std::cout << "ClapTrap " << name << " Created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source) {
    *this = source;
    std::cout << "ClapTrap " << name << " Created by copy!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " Destroyed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &source) {
    if (this == &source)
        return *this;

    name = source.name;
    HitPoints = source.HitPoints;
    EnergyPoints = source.EnergyPoints;
    AttackDamage = source.AttackDamage;
    return *this;
}

std::string ClapTrap::getName() const { return name; }
unsigned int ClapTrap::getHitPoints() const { return HitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return EnergyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return AttackDamage; }

void ClapTrap::setName(const std::string &name) { this->name = name; }
void ClapTrap::setHitPoints(unsigned int HitPoints) { this->HitPoints = HitPoints; }
void ClapTrap::setEnergyPoints(unsigned int EnergyPoints) { this->EnergyPoints = EnergyPoints; }
void ClapTrap::setAttackDamage(unsigned int AttackDamage) { this->AttackDamage = AttackDamage; }

void ClapTrap::attack(const std::string& target) {
    if (HitPoints == 0)
    {
        std::cout << "ClapTrap" << name << "can't attack 💀" << std::endl;
        return;
    }
    if (EnergyPoints == 0)
    {
        std::cout << "ClapTrap" << name << "can't attack, no Energy Points left! 🪫" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage! 💥" << std::endl;
    EnergyPoints--;
}


void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "Robot " << name << " takes " << amount << " points of damage! 😵" << std::endl;
    if (HitPoints == 0)
        return;
    if (amount >= HitPoints)
    {
        HitPoints = 0;
        std::cout << "Robot " << name << " is dead! 💀" << std::endl;
    }
    else
        HitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (HitPoints == 0)
    {
        std::cout << "Robot " << name << " can't be repaired, it's dead! 💀" << std::endl;
        return;
    }
    if (EnergyPoints == 0)
    {
        std::cout << "Robot " << name << " can't be repaired, no Energy Points left! 🪫" << std::endl;
        return;
    }
    std::cout << "Robot " << name << " is being repaired for " << amount << " points! 🛠️" << std::endl;
    EnergyPoints--;
    HitPoints += amount;
}