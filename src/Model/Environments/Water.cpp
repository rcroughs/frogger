#include "Water.h"


Water::Water() : isMoving{true}, color(FL_BLUE) {
    for (int i = 0; i < 5; i++) {
        logs[i] = new Log(float(i * 20));
    }
}
void Water::handleGame(Game *currentGame) {
    bool onLog = false;
    for (auto &log: logs) {
        if (log->contains(currentGame->getPlayer()->getPosition().x)) {
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
            log->moveRight();
        }
    }
}

std::array<Prop *, 5> *Water::getProps() {
    return &logs;
}