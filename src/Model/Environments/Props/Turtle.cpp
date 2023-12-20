#include "Turtle.h"
#include <memory>

bool Turtle::contains(float playerPosition) {
  if (position < playerPosition && playerPosition < getRightCorner())
    return true;
  return false;
}

void Turtle::move() {
  if (getRightCorner() < 0) {
    position = 100;
  } else {
    position -= 0.2f;
  }
}

void Turtle::handleGame(Game *currentGame) {
  std::shared_ptr<Player> player = currentGame->getPlayer();
  player->setPosition(
      Position{player->getPosition().x - 0.2f, player->getPosition().y});
}