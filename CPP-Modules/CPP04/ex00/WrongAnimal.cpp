#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

WrongCat::WrongCat() : WrongAnimal() {
    type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}