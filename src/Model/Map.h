#ifndef FROGGER_MAP_H
#define FROGGER_MAP_H

#include "Game.h"
#include "array"
#include <memory>
#include <string>

class Environment;
class Game;

enum EnvironmentType { LOG = '1', TURTLE = '2', ROAD = '3', SIDEWALK = '4' };
enum Directions { LEFT = '0', RIGHT = '1' };
enum Speed { SLOW = 1, MEDIUM = 2, FAST = 3 };

class Map {
public:
  Map();
  Map(std::string mapId);
  [[nodiscard]] virtual std::shared_ptr<Environment> getEnvironment(int index) const;
  virtual void deleteEnvironment(int index);
  virtual void setEnvironment(int index,
                              std::shared_ptr<Environment> new_environment);
  virtual void resetEnvironments();

  virtual void updateProps() const;
  virtual void handleGame(Game *currentGame) const;

  virtual bool createMap(std::string mapId);

  virtual std::string getMapId() const;

protected:

  virtual bool createLogEnvironment(std::string mapId, int &stringCount, int environmentCount);
  virtual bool createTurtleEnvironment(std::string mapId, int &stringCount, int environmentCount);
  virtual bool createRoadEnvironment(std::string mapId, int &stringCount, int environmentCount);

private:
  std::array<std::shared_ptr<Environment>, 13> environments{nullptr};
};

#endif // FROGGER_MAP_H