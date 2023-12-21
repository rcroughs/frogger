#include "Turtle.h"
#include <ctime>
#include <memory>

bool Turtle::contains(float playerPosition) {
  if (position < playerPosition && playerPosition < getRightCorner() && visible)
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

void Turtle::update() {
  if (visible) {
    srand(clock());
    if (rand() % 600 == 0) {
      visible = false;
      invisibleTimer = 180 + (rand() % 120);
    }
  } else {
    invisibleTimer--;
    if (invisibleTimer == 0) {
      visible = true;
    }
  }
}