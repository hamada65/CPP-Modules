#include "ClapTrap.hpp"

int main() {
    ClapTrap clap1("ClapTrap1");
    ClapTrap clap2("ClapTrap2");

    clap1.attack(clap2.getName());
    clap2.takeDamage(5);
    clap2.beRepaired(3);

    clap2.attack(clap1.getName());
    clap1.takeDamage(10);
    clap1.beRepaired(5);

    return 0;
}