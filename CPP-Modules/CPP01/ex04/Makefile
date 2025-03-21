# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 11:08:51 by acarpent          #+#    #+#              #
#    Updated: 2025/03/18 12:19:29 by acarpent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex04

CXXFLAGS += -Wall -Wextra -Werror -std=c++98

SRC = 	main.cpp replace.cpp

OBJ_DIR = Objs
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

TEXTFILE = textfile

REPLACE = textfile.replace

all: $(NAME) $(TEXTFILE)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(TEXTFILE):
	@echo "Generating random text file..."
	@head /dev/urandom | tr -dc A-Za-z | head -c 10000000 > $(TEXTFILE)

clean:
	rm -f $(OBJ) $(TEXTFILE) $(REPLACE)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re