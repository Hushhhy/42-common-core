# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 12:00:49 by acarpent          #+#    #+#              #
#    Updated: 2025/03/17 12:08:13 by acarpent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03

CXXFLAGS += -Wall -Wextra -Werror -std=c++98

SRC = 	main.cpp\
		HumanA.cpp\
		HumanB.cpp\
		Weapon.cpp\

OBJ_DIR = Objs
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re