#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        void makeSound() const;
        std::string getType() const;
};

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        ~WrongCat();
        void makeSound() const;
};

#endif