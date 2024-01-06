#include "MapFactory.h"
#include "Environments/Road.h"
#include "Environments/SideWalk.h"
#include "Environments/Water.h"
#include "Game.h"
#include <memory>
#include <string>

bool MapFactory::createLogEnvironment(std::string mapId, int &stringCount,
                                      std::shared_ptr<Map> map,
                                      int environmentCount) const {
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
  map->setEnvironment(environmentCount, std::make_shared<Water>(flow, 0));
  stringCount += 1;
  return true;
}

bool MapFactory::createTurtleEnvironment(std::string mapId, int &stringCount,
                                         std::shared_ptr<Map> map,
                                         int environmentCount) const {
  map->setEnvironment(
      environmentCount,
      std::make_shared<Water>(std::stoi(std::string(&mapId.at(stringCount), 1)),
                              std::stoi(std::string(&mapId.at(stringCount + 1), 1))));
  stringCount += 2;
  return true;
}

bool MapFactory::createRoadEnvironment(std::string mapId, int &stringCount,
                                       std::shared_ptr<Map> map,
                                       int environmentCount) const {
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
  map->setEnvironment(environmentCount,
                      std::make_shared<Road>(direction, flow, 0));
  stringCount += 1;
  return true;
}

std::shared_ptr<Map> MapFactory::createMap(std::string mapId) const {
  std::shared_ptr<Map> map = std::make_shared<Map>();
  map->setEnvironment(0, std::make_shared<SideWalk>());
  int stringCount = 0;
  int environmentCount = 1;
  while (stringCount < int(mapId.length())) {
    if (environmentCount == 13) {
      return nullptr;
    }
    if (mapId.at(stringCount) == LOG) {
      stringCount++;
      createLogEnvironment(mapId, stringCount, map, environmentCount);
      environmentCount++;
    } else if (mapId.at(stringCount) == TURTLE) {
      stringCount++;
      createTurtleEnvironment(mapId, stringCount, map, environmentCount);
      environmentCount++;
    } else if (mapId.at(stringCount) == ROAD) {
      stringCount++;
      createRoadEnvironment(mapId, stringCount, map, environmentCount);
      environmentCount++;
    } else if (mapId.at(stringCount) == SIDEWALK) {
      stringCount++;
      map->setEnvironment(environmentCount, std::make_shared<SideWalk>());
      environmentCount++;
    } else {
      return nullptr;
    }
  }
  map->setEnvironment(12, std::make_shared<Water>());
  map->getEnvironment(12)->generateProps(1);
  return map;
}