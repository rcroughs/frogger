#include "Water.h"

Water::Water() : isMoving{true}, color(FL_BLUE) {
    for (int i = 0; i < 5; i++) {
        logs.push_back(new Log(float(i * 20)));
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