FROM debian:buster

RUN apt update
RUN apt upgrade -y
RUN apt install npm curl netcat postgresql-client procps -y

# COPY ./https/key.key /etc/ssl/private/
# COPY ./https/certificate.cert /etc/ssl/certs/
# RUN openssl req -x509 -newkey rsa:2048 -nodes -sha256 -subj '/CN=localhost' -keyout /etc/ssl/private/key.pem -out /etc/ssl/certs/cert.pem -days 365

WORKDIR /app
COPY package*.json ./
COPY . .

RUN npm install -g n
RUN n 14
RUN npm install

RUN	npm install webpack --save-dev \
	&& npm install prisma --save-dev\
	&& npm install --python=python3

RUN npm run build
RUN chmod 777 ./init_psql.sh

EXPOSE 8080

# CMD ["sh", "./init_psql.sh"]
ENTRYPOINT [ "./init_psql.sh" ]