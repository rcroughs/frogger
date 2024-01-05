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

  virtual void move_up();
  virtual void move_down();
  virtual void move_right();
  virtual void move_left();

private:
  Position current_position;
  Direction current_direction;
};

#endif //_PLAYER_H