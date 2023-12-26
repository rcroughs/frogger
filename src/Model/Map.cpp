#include "Map.h"

void Map::updateProps() {
  for (int i = 0; i < 13; i++) {
    environments.at(i)->updateProps();
  }
}

void Map::handleGame(Game *currentGame) {
  environments.at(currentGame->getPlayer()->getPosition().y)
      ->handleGame(currentGame);
}

void Map::resetEnvironments() {
  for (int i = 0; i < environments.size(); i++) {
    delete environments.at(i);
  }
}

std::string Map::getMapId() {
  std::string id = "";
  for (int i = 1; i < environments.size() - 1; i++) {
    id += environments.at(i)->getId();
  }
  return id;
}