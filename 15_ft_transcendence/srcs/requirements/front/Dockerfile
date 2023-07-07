# Stage 1: Build the application
# FROM node:16-alpine as build
FROM node:16-alpine

WORKDIR /app

# Copy package json files and install dependencies
COPY package*.json ./
RUN npm install -g npm
RUN apk add --update --no-cache python3 make gcc g++ libc-dev
RUN npm install

# Copy other source code files
COPY . .

# Run the build script
# RUN npm run build

# Stage 2: Run the application in a development environment
# FROM node:14-alpine

# Install global packages
RUN npm install -g speakeasy qrcode axios python3
RUN apk add --update --no-cache openssl

RUN npm run build
RUN npm install -g serve
# Set the working directory
# WORKDIR /app

# Copy source code files and node modules from build stage
# COPY --from=build /app /app

# Expose the port
EXPOSE 3000

# Run the start script with hot-reload enabled (substitute "start:dev" with the actual script in your package.json that starts the dev server)
CMD ["npm", "run", "serve"]