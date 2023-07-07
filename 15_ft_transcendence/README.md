# Projet FT_Transcendence

Ce projet est une application web développée avec une architecture de microservices. Il contient une partie front-end et une partie back-end, ainsi qu'une base de données PostgreSQL. 

Le projet est structuré de la manière suivante :

```
.
├── Makefile
└── srcs
    ├── docker-compose.yml
    └── requirements
        |
        ├── back
        |   |── package.json
        │   ├── prisma
        │   ├── src
        └── front
            ├── package.json
            └── src

```

## Prérequis
 - Docker
 - Docker Compose

## Détails du projet

 - `Makefile` : Contient des commandes pour faciliter le lancement et l'arrêt des services.
 - `srcs/docker-compose.yml` : Fichier de configuration Docker Compose pour déployer les services du projet.

## Front-end
Le front-end est développé en React et est situé dans le dossier srcs/requirements/front.

- `package.json` : Contient les dépendances et les scripts NPM.
- `package-lock.json` : Fichier généré automatiquement pour décrire l'arbre des dépendances.
- `public` : Dossier contenant les fichiers statiques publics.
- `README.md` : Fichier d'instructions pour le front-end.
- `src` : Dossier contenant le code source du front-end.
- `tsconfig.json` : Fichier de configuration TypeScript pour le front-end.

#### Création de composants

Dans le front-end, le code est organisé sous forme de composants React. Chaque composant est généralement composé d'un fichier .tsx contenant le code TypeScript et JSX, ainsi que d'un fichier .scss pour le style. Les composants sont stockés dans le dossier src/components.

##### Exemple 

1. Créez un nouveau dossier pour le composant dans src/components.
2. Créez un fichier .tsx pour le code du composant, en utilisant le nom du composant comme nom de fichier. Par exemple, pour un composant MyComponent, créez un fichier MyComponent.tsx.
3. Créez un fichier .scss pour le style du composant, en utilisant le même nom que le fichier .tsx. Par exemple, pour le composant MyComponent, créez un fichier MyComponent.scss.
4. Dans le fichier .tsx, importez le fichier .scss en ajoutant l'instruction suivante en haut du fichier :

`import './MyComponent.scss';`

5. Développez votre composant comme d'habitude en utilisant TypeScript et JSX.

Avec cette approche, chaque composant est autonome et contient son propre style. Cette méthode facilite la maintenance du code, car il est plus simple de localiser et de modifier les styles spécifiques à un composant.





## Back-end
Le back-end est développé en NestJS et est situé dans le dossier srcs/requirements/back.

- `dist` : Dossier contenant les fichiers compilés.
- `nest-cli.json` : Fichier de configuration pour Nest CLI.
- `package.json` : Contient les dépendances et les scripts NPM.
- `package-lock.json` : Fichier généré automatiquement pour décrire l'arbre des dépendances.
- `prisma` : Dossier contenant les fichiers de configuration Prisma pour la base de données.
- `README.md` : Fichier d'instructions pour le back-end.
- `src` : Dossier contenant le code source du back-end.
- `test` : Dossier contenant les tests du back-end.
- `tsconfig.build.json` : Fichier de configuration TypeScript pour la compilation du back-end.
- `tsconfig.json` : Fichier de configuration TypeScript pour le back-end.

### Base de données

La base de données est PostgreSQL et est déployée via Docker Compose.

## Déploiement

 1. Ouvrez un terminal à la racine du projet.
 2. Exécutez la commande `make` pour lancer les services.

Les services seront accessibles aux adresses suivantes :

- Frontend : http://localhost:3000
- Backend : http://localhost:8080
- Base de données : `localhost:5434` (PostgreSQL)

Pour arrêter les services, exécutez la commande `make down` dans le terminal.
