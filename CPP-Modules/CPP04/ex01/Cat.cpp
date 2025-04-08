#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
    delete brain;
    brain = NULL;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    if(!brain) {
        std::cerr << "Error: Brain is null!" << std::endl;
        return NULL;
    }
    return brain;
}