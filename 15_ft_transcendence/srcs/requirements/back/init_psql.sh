#!/bin/bash
while ! nc -z database 5432;
    do
        echo 'Waiting for the PostgreSQL Server'
        sleep 1
    done;

echo 'PostgreSQL Server is up - executing command'

#npx prisma migrate deploy
npm run start:dev
