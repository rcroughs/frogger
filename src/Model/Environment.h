#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Environments/Props/Prop.h"
#include "FL/Fl.H"
#include <memory>
#include <vector>

class Game;
class Prop;

class Environment {
public:
  [[nodiscard]] virtual Fl_Color getColor() const = 0;
  [[nodiscard]] virtual std::vector<std::shared_ptr<Prop>> getProps() const = 0;
  virtual void handleGame(Game *currentGame) = 0;
  virtual void updateProps() = 0;
  virtual void generateProps(short id) = 0;
  [[nodiscard]] virtual std::string getId() const = 0;
};

#endif