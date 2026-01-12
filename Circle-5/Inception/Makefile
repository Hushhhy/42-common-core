NAME = inception

all: build up

build:
	@mkdir -p /home/${USER}/data/wordpress
	@mkdir -p /home/${USER}/data/mariadb
	docker-compose -f ./srcs/docker-compose.yml build

up:
	docker-compose -f ./srcs/docker-compose.yml up -d

down:
	docker-compose -f ./srcs/docker-compose.yml down

clean: down
	docker system prune -af

fclean: clean
	@sudo rm -rf /home/${USER}/data/wordpress/*
	@sudo rm -rf /home/${USER}/data/mariadb/*

re: fclean all

.PHONY: all build up down clean fclean re