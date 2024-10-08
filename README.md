# 🐸 Frogger
Frogger est un jeu crée en 1981. Dans ce jeu, vous controlez une grenouille qui commence en bas de l'écran que vous devez emmener sur le nénuphar libre en haut de l'écran.

## Modèle de conception
Pour ce projet, il est demandé d'utiliser le modèle de conception *Modèle-Vue-Controlleur*.
Il est également demandé de suivre les règles suivantes:
 - Décomposition en classes et en fichiers
 - Aucune variable globale
 - Pas de logique répétée
 - Commentaire et documentation du code 
 - Code des méthodes assez courte
 - Utilisation correcte des constructeurs et destructeurs
 - Utilisation des fonctions simples de FLTK uniquement
 
 Le code doit également être le plus modulable que possible

## Organisation des fichiers
 - `src/`: Contient tous les fichiers sources (.cpp, .hpp)
 - `build/`: Contient tous les fichiers compilés (pas dans le repo parce que produit par `make`)
 - `docs/`: Contient toute la documentation
 - `res/`: Contient les ressources, tel que les images, polices, etc.
 - `test/`: Contient les tests unitaires
 - `Makefile`: Makefile à modifier progressivement au cours du projet

## Compiler le projet
Le projet peut être compilé avec la commande `make` a la racine du projet. L'exécutable se trouvera dans le dossier `build/`.
```sh
 > mkdir build
 > make
 > ./frogger
```

## Etapes du projet
 - [x] Taches de bases
    - [x] Grenouille: Avoir une grenouille fonctionnelle qui peut se déplacer avec ZQSD et WASD.
    - [x] 13 rangées: 1 et 7 sont des trottoirs, 2 à 6 sont des routes avec des voitures qui se déplacent, 8 à 13 sont des rangées d'eau, avec des buches, et 13 est une rangée de nénuphar.
    - [x] Message de victoire
    - [x] Message d'échec
 - [ ] Taches additionnelles a faire après celles de bases
    - [x] Les rangées d'eau qui sont composées de troncs d'arbres et de tortues
    - [x] Nous mettons des nénuphars a la dernière ligne, lorsqu'une grenouille va sur un nénuphar, une nouvelle grenouille apparait un bas de l'écran et le jeu se finit quand tous les nénuphars sont occupé
    - [x] Ajout d'un système de vies 
    - [x] Les tortues peuvent plonger
    - [x] La grenouille regarde dans le sens de la direction précedente
    - [x] Afficher un score (trouver une méthode pour le calculer)
    - [x] Afficher un meilleur score
    - [x] Ecran d'acceuil où on voit notre nom qui s'affiche pendant une seconde
    - [x] Niveau et sélection des niveau 
    - [ ] Editeur de Niveau
 - [ ] Rapport de maximum 10 pages

### Dates importantes
 - *14 janvier à 23h59*: Remise du projet
 - *19 janvier à 13h00 au NO2.O8.114*: Démonstration et réponse aux questions
