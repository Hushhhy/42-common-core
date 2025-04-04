#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap claptrap("Clappy");

    claptrap.attack("target1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
    claptrap.takeDamage(10);
    claptrap.attack("target2");

    ScavTrap scav("Scavvy");

    scav.attack("target2");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    FragTrap Frag("Froggy");

    Frag.attack("target3");
    Frag.takeDamage(50);
    Frag.beRepaired(30);
    Frag.highFivesGuys();

    return 0;
}