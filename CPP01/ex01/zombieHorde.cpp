#include "Zombie.hpp"


Zombie* zombieHorde( int N, std::string name ) {
	Zombie *Hord = new Zombie[N];
	for (int i = 0; i < N ; i++)
		Hord[i].setName(name);
	return Hord;
}