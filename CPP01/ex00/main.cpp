#include "Zombie.hpp"

int main()
{
	Zombie* zombie1 = newZombie("Zombie1");
	zombie1->announce();
	delete zombie1;
	randomChump("Zombie 3ayaaaaan");
	return 0;
}