#include "Log.h"
#include "../../Game.h"
#include "../../Player.h"
#include <memory>

bool Log::contains(float playerPosition) {
  if ((leftCorner) <= playerPosition && playerPosition <= (leftCorner + size)) {
    return true;
  }
  return false;
}

void Log::move() {
  if (getRightCorner() >= 130) {
    leftCorner = 0 - size;
  } else {
    leftCorner = leftCorner + speed * (0.2f);
  }
}

void Log::handleGame(Game *currentGame) {
  std::shared_ptr<Player> player = currentGame->getPlayer();
  player->setPosition(Position{player->getPosition().x + (speed * 0.2f),
                               player->getPosition().y});
}