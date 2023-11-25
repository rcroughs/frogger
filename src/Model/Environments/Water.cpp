#include "Water.h"

void Water::handleGame(Game *currentGame) {
    bool onLog = false;
    for (auto &log: logs) {
        if (log.contains(currentGame->getPlayer()->getPosition().x)) {
            onLog = true;
        }
    }
    if (onLog) {
        isMoving = false;
    } else {
        currentGame->changeLoosingState();
    }
}

void Water::updateProps() {
    if (isMoving) {
        for (auto &log : logs) {
            log.moveRight();
        }
    }
}