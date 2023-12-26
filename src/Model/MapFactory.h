#ifndef _FROGGER_MAPFACTORY_H_
#define _FROGGER_MAPFACTORY_H_

#include <memory>
#include <string>
#include "Map.h"

class Map;

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