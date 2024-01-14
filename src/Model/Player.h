////////// Player Header File - src/Model/Player.h //////////
// Description: This struct is used to represent the player
// Constructor takes: A starting position and a starting direction
////////// FROGGER ////////////////////////////////////////

#ifndef _PLAYER_H
#define _PLAYER_H

#include "Direction.h"
#include "Position.h"

class Player {
public:
  Player(Position position, Direction direction)
      : current_position{position}, current_direction{direction} {}

  // getters and setters
  [[nodiscard]] virtual Position getPosition() const;
  virtual void setPosition(Position new_position);
  [[nodiscard]] virtual Direction getDirection() const;
  virtual void setDirection(Direction new_direction);
  [[nodiscard]] virtual bool isInScreen() const;

  // Player deplacements
  virtual void moveUp();
  virtual void moveDown();
  virtual void moveRight();
  virtual void moveLeft();

private:
  Position current_position;
  Direction current_direction;
};

#endif //_PLAYER_H