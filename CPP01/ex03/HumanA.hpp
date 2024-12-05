#include "Weapon.hpp"
#ifndef HUMANA_HPP
#define HUMANA_HPP

class HumanA {
	private:
		std::string name;
		Weapon *_weapon;
	public:
	HumanA(const std::string &name,Weapon &Weapon);
	void attack();
};

#endif