#ifndef _PLAYER_H
#define _PLAYER_H

#include "Position.h"
#include "Direction.h"

class Player {
private:
    Position current_position;
    Direction current_direction;
public:
    Player(Position position, Direction direction) : current_position{position}, current_direction{direction} {}

    virtual Position getPosition() {return this->current_position;}
    virtual void setPosition(Position new_position) {current_position = new_position;}
    virtual Direction getDirection() {return this->current_direction;}
    virtual void setDirection(Direction new_direction) {current_direction = new_direction;}

    virtual void move_up();
    virtual void move_down();
    virtual void move_right();
    virtual void move_left();
};

#endif