#include "Water.h"

Water::Water() : isMoving{true}, color(FL_BLUE) {
    int usedSpace = 0;
    int logCounter = 0;
    while (usedSpace + 20 < 100) {
        srand(clock());
        // Génération de la taille de la bûche (30, 40, ou 70 % de l'écran en longueur)
        int size = 0;
        while (size != 1 && size != 2 && size != 3) {
            size = rand() % 7;
        }
        size *= 10;
        // Génération de la position
        float position = 0;
        if (logCounter - 1 >= 0) {
            position = logs.at(logCounter-1)->getPosition() + (logs.at(logCounter-1)->getSize()) + 20;
        } else {
            position = (rand() % 3) * 10;
        }
        logs.push_back(new Log(float(size), float(position)));
        logCounter++;
        usedSpace = position + size;
    }
}

void Water::handleGame(Game *currentGame) {
    bool onLog = false;
    for (auto &log: logs) {
        if (log->contains(currentGame->getPlayer()->getPosition().x)) {
            onLog = true;
            Player *player = currentGame->getPlayer();
            player->setPosition(Position{player->getPosition().x + 0.2f, player->getPosition().y});
        }
    }
    if (!onLog) {
        currentGame->changeLoosingState();
    }
}

void Water::updateProps() {
    if (isMoving) {
        for (auto &log : logs) {
            log->moveRight();
        }
    }
}

std::vector<Prop*> &Water::getProps() {
    return logs;
}