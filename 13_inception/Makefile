all: 
	if [ ! -d "/home/halvarez/data" ]; then \
		mkdir -p /home/halvarez/data/wordpress; \
		mkdir -p /home/halvarez/data/mariadb; \
	else \
		echo "Inception files already created !"; \
	fi
	if [ ! -f srcs/.env ]; then cp ~/.env srcs/.; fi
	docker compose -f srcs/docker-compose.yml up

down:
	docker compose -f srcs/docker-compose.yml down

mdb: down
	docker rmi -f srcs-mariadb
	docker build -t srcs-mariadb srcs/requirements/mariadb/.
	docker compose -f srcs/docker-compose.yml up

wp: down
	docker rmi -f srcs-wordpress
	docker build -t srcs-wordpress srcs/requirements/wordpress/.
	docker compose -f srcs/docker-compose.yml up

ngx: down
	docker rmi -f srcs-nginx
	docker build -t srcs-nginx srcs/requirements/nginx/.
	docker compose -f srcs/docker-compose.yml up

clean: down
	docker system prune -af
	docker image rm -f $(docker images -qa)

fclean: clean
	sudo rm -rf /home/halvarez/data

re:
	make fclean
	make all

.PHONY: all re down clean
