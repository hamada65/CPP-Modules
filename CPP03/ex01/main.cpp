#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap1("ClapTrap1");
    ClapTrap clap2("ClapTrap2");

    clap1.attack(clap2.getName());
    clap2.takeDamage(5);
    clap2.beRepaired(3);

    clap2.attack(clap1.getName());
    clap1.takeDamage(10);
    clap1.beRepaired(5);

    std::cout << "Testing ScavTrap:" << std::endl;

    ScavTrap scav1("ScavTrap1");
    ScavTrap scav2("ScavTrap2");

    scav1.attack(scav2.getName());
    scav2.takeDamage(15);
    scav2.beRepaired(10);

    scav2.attack(scav1.getName());
    scav1.takeDamage(20);
    scav1.beRepaired(15);

    scav1.guardGate();
    scav2.guardGate();

    return 0;
}