#ifndef _PLAYER_H
#define _PLAYER_H

#include "Direction.h"
#include "Position.h"
#include <iostream>

class Player {
public:
  Player(Position position, Direction direction)
      : current_position{position}, current_direction{direction} {}

  [[nodiscard]] virtual Position getPosition() const;
  virtual void setPosition(Position new_position);
  [[nodiscard]] virtual Direction getDirection() const;
  virtual void setDirection(Direction new_direction);
  [[nodiscard]] virtual bool isInScreen() const;

  virtual void moveUp();
  virtual void moveDown();
  virtual void moveRight();
  virtual void moveLeft();

private:
  Position current_position;
  Direction current_direction;
};

#endif //_PLAYER_H