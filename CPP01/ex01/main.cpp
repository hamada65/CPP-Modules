#include "Zombie.hpp"

int main()
{
	Zombie *Hord = zombieHorde(5, "Zombie");

	for (int i = 0; i < 5 ; i++)
		Hord[i].announce();
	delete[] Hord;
	return 0;
}