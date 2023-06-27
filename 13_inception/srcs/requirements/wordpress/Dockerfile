FROM	debian:buster

LABEL	version="1.0"
LABEL	maintainer="halvarez"

# Install necessary packages
RUN		mkdir -p /var/www/html; \
			apt update -y; \
			apt install -y php7.3; \
			apt install -y wget; \
			apt install -y php; \
			apt install -y php-fpm; \
			apt install -y php-common; \
			apt install -y php-cgi; \
			apt install -y php-cli; \
			apt install -y php-mysql; \
			apt install -y mariadb-client

EXPOSE	9000

# Download worpress and uncompress it
RUN		wget https://wordpress.org/wordpress-6.2.tar.gz -P /var/www/; \
			tar -xzf /var/www/wordpress-6.2.tar.gz -C /var/www/.; \
			cp -r /var/www/wordpress/. /var/www/html; \
			rm /var/www/wordpress-6.2.tar.gz; \
		wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -P /var/www; \
			chmod +x /var/www/wp-cli.phar; \
			mv /var/www/wp-cli.phar /usr/local/bin/wp

# Copy configuration files for dedicated inception configuration 
COPY	/conf/wordpress.sh /var/www/.
COPY    /conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

RUN		mkdir -p /run/php; \
		chmod +x /var/www/wordpress.sh; \
		chown -R root:root /var/www/html

ENTRYPOINT	["./var/www/wordpress.sh"]

#CMD		["/usr/sbin/php-fpm7.3", "-F"]
