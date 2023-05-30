FROM	debian:buster

LABEL	version="1.0"
LABEL	maintainer="halvarez"

RUN		apt update -y; \
		apt install -y mariadb-server vim

EXPOSE	3306

RUN 	mkdir -p /var/mariadb
COPY 	conf/. /var/mariadb/.
COPY 	conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf

RUN 	chmod +x /var/mariadb/mariadb.sh

CMD		["/var/mariadb/mariadb.sh"]
