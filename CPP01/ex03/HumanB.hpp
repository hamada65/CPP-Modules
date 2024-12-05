#include "Weapon.hpp"
#ifndef HUMANB_HPP
#define HUMANB_HPP

class HumanB {
	private:
		std::string name;
		Weapon *_weapon;
	public:
	HumanB(const std::string &name);
	void attack();
	void setWeapon(Weapon &Weapon);
};

#endif