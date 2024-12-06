#include "HumanA.hpp"

HumanA::HumanA(const std::string &name,Weapon &Weapon) : name(name), _weapon(Weapon) { } 

void HumanA::attack() {
	std::cout << this->name + " attacks with their " + this->_weapon.getType() << std::endl;
}