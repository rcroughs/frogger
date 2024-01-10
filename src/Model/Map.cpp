#include "Map.h"
#include <cstddef>

Map::Map() : environments{} {}

std::shared_ptr<Environment> Map::getEnvironment(int index) const {
  return environments.at(index);
}

void Map::deleteEnvironment(int index) { environments.at(index) = nullptr; }

void Map::setEnvironment(int index,
                         std::shared_ptr<Environment> new_environment) {
  deleteEnvironment(index);
  environments[index] = new_environment;
}

void Map::resetEnvironments() {
  for (size_t i = 0; i < environments.size(); i++) {
    deleteEnvironment(i);
  }
}

void Map::updateProps() const {
  for (int i = 0; i < 13; i++) {
    environments.at(i)->updateProps();
  }
}

void Map::handleGame(Game *currentGame) const {
  environments.at(currentGame->getPlayer()->getPosition().y)
      ->handleGame(currentGame);
}

std::string Map::getMapId() const {
  std::string id = "";
  for (size_t i = 1; i < environments.size() - 1; i++) {
    id += environments.at(i)->getId();
  }
  return id;
}