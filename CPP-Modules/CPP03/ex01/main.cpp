#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

    return 0;
}