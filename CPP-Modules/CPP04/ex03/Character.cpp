#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
}

Character::Character(Character const & src) : name(src.name) {
    for (int i = 0; i < 4; ++i)
        inventory[i] = src.inventory[i] ? src.inventory[i]->clone() : NULL;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
}

Character & Character::operator=(Character const & rhs) {
    if (this != &rhs) {
        name = rhs.name;
        for (int i = 0; i < 4; ++i) {
            delete inventory[i];
            inventory[i] = rhs.inventory[i] ? rhs.inventory[i]->clone() : NULL;
        }
    }
    return *this;
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            return;
        }
    }
    std::cout << name << "'s inventory is full" << std::endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !inventory[idx]) {
        std::cout << "Invalid index or no materia to unequip" << std::endl;
        return;
    }
    std::cout << name << " unequipped " << inventory[idx]->getType() << std::endl;
    delete inventory[idx];
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || !inventory[idx]) {
        std::cout << "Invalid index or no materia to use" << std::endl;
        return;
    }
    inventory[idx]->use(target);
}

