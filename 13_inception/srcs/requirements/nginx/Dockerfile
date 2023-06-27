FROM	debian:buster

LABEL	version="1.0"
LABEL	maintainer="halvarez"

RUN		apt update -y; \
			apt install -y nginx openssl; \
		mkdir /var/run/nginx

EXPOSE	443

COPY	conf/nginx.conf /etc/nginx/nginx.conf

RUN		chmod 755 /var/www/html; \
		chown -R www-data:www-data /var/www/html; \
		openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
			-keyout /etc/ssl/private/nginx_halvarez.key \
			-out /etc/ssl/certs/nginx_halvarez.crt -subj "/C=FR/ST=IDF/L=Paris/O=wordpress/CN=halvarez.42.fr";

CMD		["nginx", "-g", "daemon off;"]
