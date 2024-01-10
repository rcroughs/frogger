#include "Map.h"
#include "Environments/Road.h"
#include "Environments/SideWalk.h"
#include "Environments/Water.h"
#include <cstddef>

Map::Map(std::string mapId) : Map{} {
  createMap(mapId);
}

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

bool Map::createLogEnvironment(std::string mapId, int &stringCount,
                               int environmentCount) {
  int speed = std::stoi(std::string(&mapId.at(stringCount), 1));
  float flow;
  switch (speed) {
  case SLOW:
    flow = 1.0f;
    break;
  case MEDIUM:
    flow = 1.5f;
    break;
  case FAST:
    flow = 2.0f;
    break;
  default:
    return false;
  }
  setEnvironment(environmentCount, std::make_shared<Water>(flow, 0));
  stringCount += 1;
  return true;
}

bool Map::createTurtleEnvironment(std::string mapId, int &stringCount,
                                  int environmentCount) {
  setEnvironment(environmentCount,
                 std::make_shared<Water>(
                     std::stoi(std::string(&mapId.at(stringCount), 1)),
                     std::stoi(std::string(&mapId.at(stringCount + 1), 1))));
  stringCount += 2;
  return true;
}

bool Map::createRoadEnvironment(std::string mapId, int &stringCount,
                                       int environmentCount) {
  char direction = mapId.at(stringCount) == '0' ? 'l' : 'r';
  stringCount += 1;
  int speed = std::stoi(std::string(&mapId.at(stringCount), 1));
  float flow;
  switch (speed) {
  case SLOW:
    flow = 1.0f;
    break;
  case MEDIUM:
    flow = 1.5f;
    break;
  case FAST:
    flow = 2.0f;
    break;
  default:
    return false;
  }
  setEnvironment(environmentCount,
                      std::make_shared<Road>(direction, flow, 0));
  stringCount += 1;
  return true;
}

bool Map::createMap(std::string mapId) {
  setEnvironment(0, std::make_shared<SideWalk>());
  int stringCount = 0;
  int environmentCount = 1;
  while (stringCount < int(mapId.length())) {
    if (environmentCount == 13) {
      return false;
    }
    if (mapId.at(stringCount) == LOG) {
      stringCount++;
      createLogEnvironment(mapId, stringCount, environmentCount);
      environmentCount++;
    } else if (mapId.at(stringCount) == TURTLE) {
      stringCount++;
      createTurtleEnvironment(mapId, stringCount, environmentCount);
      environmentCount++;
    } else if (mapId.at(stringCount) == ROAD) {
      stringCount++;
      createRoadEnvironment(mapId, stringCount, environmentCount);
      environmentCount++;
    } else if (mapId.at(stringCount) == SIDEWALK) {
      stringCount++;
      setEnvironment(environmentCount, std::make_shared<SideWalk>());
      environmentCount++;
    } else {
      return false;
    }
  }
  setEnvironment(12, std::make_shared<Water>(1, 1));
  return true;
}