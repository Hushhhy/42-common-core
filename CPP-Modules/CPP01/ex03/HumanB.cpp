/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:15:57 by acarpent          #+#    #+#             */
/*   Updated: 2025/03/18 10:46:53 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name),  weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon) {
     this->weapon = &weapon;
}

void HumanB::attack() const {
     if (weapon) {
          std::cout << name << " attacks with their " << weapon->getType() << std::endl;
     } else {
          std::cout << name << " has no weapon to attack with" << std::endl;
     }
}