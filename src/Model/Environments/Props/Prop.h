#ifndef FROGGER_PROP_H
#define FROGGER_PROP_H

#include "../../Game.h"
#include "FL/Fl.H"
#include "FL/Fl_PNG_Image.H"
#include <random>

class Game;

class Prop {
public:
  [[nodiscard]] virtual float getPosition() const = 0;
  [[nodiscard]] virtual float getRightCorner() const = 0;
  [[nodiscard]] virtual Fl_Color getColor() const = 0;
  [[nodiscard]] virtual float getSize() const = 0;
  [[nodiscard]] virtual bool contains(float playerPosition) const = 0;
  virtual void move() = 0;
  virtual void handleGame(Game *currentGame) = 0;
  [[nodiscard]] virtual bool hasImage() const = 0;
  [[nodiscard]] virtual bool isVisible() const = 0;
  [[nodiscard]] virtual Fl_PNG_Image *getImage() const = 0;
  virtual void update() = 0;
};

#endif // FROGGER_PROP_H
