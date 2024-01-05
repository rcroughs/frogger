#ifndef FROGGER_MAP_H
#define FROGGER_MAP_H

#include "Game.h"
#include "array"
#include <memory>

class Environment;
class Game;

class Map {
public:
  Map() : environments{} {}
  [[nodiscard]] virtual std::shared_ptr<Environment> getEnvironment(int index) const;
  virtual void deleteEnvironment(int index);
  virtual void setEnvironment(int index,
                              std::shared_ptr<Environment> new_environment);
  virtual void resetEnvironments();

  virtual void updateProps() const;
  virtual void handleGame(Game *currentGame) const;

  virtual std::string getMapId() const;

private:
  std::array<std::shared_ptr<Environment>, 13> environments{nullptr};
};

#endif // FROGGER_MAP_H