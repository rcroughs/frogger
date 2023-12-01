#include "Log.h"
#include "../../Player.h"
#include "../../Game.h"

bool Log::contains(float playerPosition) {
    if ((leftCorner) <= playerPosition && playerPosition <= (leftCorner + size)) {
        return true;
    }
    return false;
}

void Log::moveRight() {
    if (getRightCorner() >= 130) {
        leftCorner = 0 - size;
    } else {
        leftCorner = leftCorner + speed * (0.2f);
    }
}

void Log::moveLeft() {
    if (leftCorner <= 0 - size) {
        leftCorner = 100;
    } else {
        leftCorner = leftCorner - 0.2f;
    }
}

void Log::handleGame(Game *currentGame) {
    Player *player = currentGame->getPlayer();
    player->setPosition(Position{player->getPosition().x + (speed * 0.2f), player->getPosition().y});
}