#include "Zombie.hpp"

Zombie::Zombie() {  }
Zombie::Zombie(const std::string name) : name(name) {}
Zombie::~Zombie() { std::cout << this->name << " Destroyed" << std::endl; }

void Zombie::setName(const std::string name) { this->name = name; }
void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
