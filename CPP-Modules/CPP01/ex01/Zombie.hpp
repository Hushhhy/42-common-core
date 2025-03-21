#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        void setName(std::string name) {this->name = name;}
        void announce() const;
};

Zombie* zombieHorde (int N, std::string name);


#endif