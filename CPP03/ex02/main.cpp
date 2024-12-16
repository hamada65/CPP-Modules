#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    std::cout << "Testing FragTrap:" << std::endl;

    FragTrap frag1("FragTrap1");
    FragTrap frag2("FragTrap2");

    frag1.attack(frag2.getName());
    frag2.takeDamage(25);
    frag2.beRepaired(20);

    frag2.attack(frag1.getName());
    frag1.takeDamage(30);
    frag1.beRepaired(25);

    frag1.highFivesGuys();
    frag2.highFivesGuys();

    return 0;
}