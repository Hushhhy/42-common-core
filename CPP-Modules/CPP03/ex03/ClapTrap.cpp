#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << name << " constructed." << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destructed." << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!"
                  << std::endl;
        _energyPoints--;
    } else
        std::cout << "ClapTrap " << _name << " cannot attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints > 0) {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount
                  << " points of damage!" << std::endl;
    } else
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " is repaired for " << amount
                  << " hit points!" << std::endl;
        _energyPoints--;
    } else
        std::cout << "ClapTrap " << _name << " cannot be repaired!" << std::endl;
}