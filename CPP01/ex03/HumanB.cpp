#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name), _weapon(NULL) { } 

void HumanB::attack() {
	if (this->_weapon)
		std::cout << this->name + " attacks with their " + this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &Weapon) {
	this->_weapon = &Weapon;
}