#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "FragTrap " << _name << " created." << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destroyed." << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        std::cout << "FragTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } else {
        std::cout << "FragTrap " << _name << " is out of energy or hit points!" << std::endl;
    }
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " is requesting a high five!" << std::endl;
}