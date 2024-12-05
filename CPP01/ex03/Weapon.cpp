#include "Weapon.hpp"

Weapon::Weapon(const std::string &Weapon) : type(Weapon) { }

const std::string &Weapon::getType() {
	return type;
}

void Weapon::setType(const std::string &type) {
	this->type = type;
}