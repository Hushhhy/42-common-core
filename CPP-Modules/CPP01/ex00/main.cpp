/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:23:40 by acarpent          #+#    #+#             */
/*   Updated: 2025/03/17 11:30:42 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int main() {
    Zombie* heapZombie = newZombie("GigaChad");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Alexis");
    
    return 0;
}