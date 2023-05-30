#!/bin/bash

if [ -f "/var/www/html/wp-config.php" ]
then
	echo "wordpress is already set !"
else
	sleep 10

	wp config create \
		--allow-root \
		--dbname=${MARIADB_NAME} \
		--dbuser=${LOGIN} \
		--dbpass=${MARIADB_ROOT_PWD} \
		--dbhost=mariadb:3306 \
		--path='/var/www/html'

	wp core install \
		--allow-root \
		--url='halvarez.42.fr' \
		--title='halvarez' \
		--admin_user=${LOGIN} \
		--admin_password=${MARIADB_ROOT_PWD} \
		--admin_email='halvarez@student.42.fr' \
		--path='/var/www/html'

	wp user create \
		--allow-root \
		--role=author $DB_USER 'halvarezh@gmail.com' \
		--user_pass=$DB_PASSWORD \
		--path='/var/www/html' >> log.txt

	if [ -f "/var/www/html/wp-config.php" ]
	then
		touch /var/www/is_wordpress
		echo "wordpress was correctly set !"
	else
		echo "---- Infinite loop ----"
			while :
			do
				sleep 1
			done
	fi
fi

/usr/sbin/php-fpm7.3 -F
