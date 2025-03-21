/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:53:43 by codespace         #+#    #+#             */
/*   Updated: 2025/03/18 13:12:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av) {
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        for (int i = 1; av[i]; i++) {
            for (int j = 0; av[i][j]; j++) {
                std::cout << (char)std::toupper(av[i][j]);
            }
        }
        std::cout << std::endl;
    }
}