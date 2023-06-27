#!/bin/bash

if [ -f /var/lib/mysql/is_mariadb ]
then
	echo "MariaDB is already set !"
else
	echo "Creating config.sql"
	touch config.sql
	echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PWD}';" >> config.sql
	echo "CREATE USER IF NOT EXISTS '${LOGIN}'@'%' IDENTIFIED BY '${MARIADB_ROOT_PWD}';" >> config.sql
	echo "CREATE DATABASE IF NOT EXISTS ${MARIADB_NAME};" >> config.sql
	echo "GRANT ALL PRIVILEGES ON ${MARIADB_NAME}.* TO '${LOGIN}'@'%' IDENTIFIED BY '${MARIADB_ROOT_PWD}' WITH GRANT OPTION;" >> config.sql
	echo "FLUSH PRIVILEGES;" >> config.sql
	echo "The config.sql file is created"
	cat config.sql

	echo "Starting mysql"
	service mysql start

	echo "Injecting config.sql"
	mysql -uroot < config.sql
	echo "The file config.sql is injected"

	echo "Stopping mysql"
	mysqladmin -uroot -p${MARIADB_ROOT_PWD} shutdown

	touch /var/lib/mysql/is_mariadb
	echo "MariaDB is configured !"
fi

echo "Executing mysqld"
exec mysqld_safe $@

echo "---- Infinite loop ----"
while :
do
	sleep 1
done
