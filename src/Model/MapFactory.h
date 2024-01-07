#ifndef _FROGGER_MAPFACTORY_H_
#define _FROGGER_MAPFACTORY_H_

#include "Map.h"
#include <memory>
#include <string>

class Map;

enum EnvironmentType { LOG = '1', TURTLE = '2', ROAD = '3', SIDEWALK = '4' };
enum Directions { LEFT = '0', RIGHT = '1' };
enum Speed { SLOW = 1, MEDIUM = 2, FAST = 3 };

class MapFactory {
public:
  std::shared_ptr<Map> createMap(std::string mapId) const;

protected:
  bool createLogEnvironment(std::string mapId, int &stringCount,
                            std::shared_ptr<Map> map, int environmentCount) const;
  bool createTurtleEnvironment(std::string mapId, int &stringCount,
                               std::shared_ptr<Map> map, int environmentCount) const;
  bool createRoadEnvironment(std::string mapId, int &stringCount,
                             std::shared_ptr<Map> map, int environmentCount) const;
};

#endif //_FROGGER_GAME_H_