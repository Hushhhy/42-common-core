#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    public:
        DiamondTrap(const std::string &name);
        ~DiamondTrap();

        void attack(const std::string &target);
        void whoAmI();

    private:
        std::string _name;
};

#endif