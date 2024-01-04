#ifndef _FROGGER_MAPFACTORY_H_
#define _FROGGER_MAPFACTORY_H_

#include <memory>
#include <string>
#include "Map.h"

class Map;

enum EnvironmentType { LOG = '1', TURTLE = '2', ROAD = '3', SIDEWALK = '4'};
enum Directions { LEFT = '0', RIGHT = '1' };
enum Speed { SLOW = 1, MEDIUM = 2 , FAST = 3};

class MapFactory {
public:
  std::shared_ptr<Map> createMap(std::string mapId);

private:
  bool createLogEnvironment(std::string mapId, int &stringCount, std::shared_ptr<Map> map,
                            int environmentCount);
  bool createTurtleEnvironment(std::string mapId, int &stringCount, std::shared_ptr<Map> map,
                               int environmentCount);
  bool createRoadEnvironment(std::string mapId, int &stringCount, std::shared_ptr<Map> map,
                              int environmentCount);
};

#endif //_FROGGER_GAME_H_