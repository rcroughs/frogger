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
        game->changeLoosingState();
    }
}

void Water::updateLogs() {
    if (isMoving) {
        for (auto &log : logs) {
            log.moveRight();
        }
    }
}