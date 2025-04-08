#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"

int main() {

    Dog* dog = new Dog();
    dog->getBrain()->setIdea(0, "Chase the ball");
    dog->getBrain()->setIdea(1, "Bark at the mailman");

    std::cout << "Dog's first idea: " << dog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog's second idea: " << dog->getBrain()->getIdea(1) << std::endl;

    Cat* cat = new Cat();
    cat->getBrain()->setIdea(0, "Climb the tree");
    cat->getBrain()->setIdea(1, "Nap in the sun");

    std::cout << "Cat's first idea: " << cat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat's second idea: " << cat->getBrain()->getIdea(1) << std::endl;

    delete dog;
    delete cat;

    return 0;
}