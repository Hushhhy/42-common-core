#include "AAnimal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

