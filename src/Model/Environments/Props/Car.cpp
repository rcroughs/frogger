#include "Car.h"

bool Car::contains(float playerPosition) {
    if (playerPosition + 7 >=  leftCorner && playerPosition <= getRightCorner()) {
        return true;
    }
    return false;
}

void Car::move() {
    if (direction == 'r') {
        if (getRightCorner() >= 130) {
            leftCorner = 0 - size;
        } else {
            leftCorner = leftCorner + speed * 0.2f;
        }
    } else {
        if (getPosition() <= -30) {
            leftCorner = 100 + size;
        } else {
            leftCorner = leftCorner - speed * 0.2f;
        }
    }
}

void Car::handleGame(Game *currentGame) {
    // pour l'instant ne sert à rien, les voitures ne font que tuer le joueur
    move();
}
