#include "Water.h"
#include "Props/Log.h"
#include "Props/LilyPad.h"
#include <ctime>

void Water::generateLogs() {
    int usedSpace = 0;
    int logCounter = 0;

    while (usedSpace + 20 < 100) {
        srand(clock());
        // Génération de la taille de la bûche
        int size = (rand() % 3 + 1) * 10;
        // Génération de la position
        float position = 0;
        if (logCounter - 1 >= 0) {
            position = props.at(logCounter - 1)->getPosition() + (props.at(logCounter - 1)->getSize()) + 20;
        } else {
            position = (rand() % 3) * 10;
        }
        props.push_back(new Log(float(size), float(position), flow));
        logCounter++;
        usedSpace = position + size;
        srand(clock());
    }
}

void Water::generateLilyPads() {
    for (int i = 1; i < 5; i++) {
        props.push_back(new LilyPad(i * 20));
    }
}

void Water::generateProps(short id) {
    switch (id) {
        case 0:
            generateLogs();
            break;
        case 1:
            generateLilyPads();
            break;
    }
}

void Water::handleGame(Game *currentGame) {
    bool onLog = false;
    for (auto &prop: props) {
        if (prop->contains(currentGame->getPlayer()->getPosition().x + 5)) {
            onLog = true;
            prop->handleGame(currentGame);
        }
    }
    if (!onLog) {
        currentGame->changeLoosingState();
    }
}

void Water::updateProps() {
    if (isMoving) {
        for (auto &prop : props) {
            prop->moveRight();
        }
    }
}

std::vector<Prop*> &Water::getProps() {
    return props;
}