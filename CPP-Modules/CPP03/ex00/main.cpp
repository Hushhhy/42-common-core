#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap("CLTP");
    claptrap.attack("target");
    claptrap.takeDamage(5);
    claptrap.attack("target");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
    claptrap.attack("target");
    claptrap.takeDamage(5);
    return 0;
}