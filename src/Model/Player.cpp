#include "Player.h"

Position Player::getPosition() const { return this->current_position; }

void Player::setPosition(Position new_position) {
  current_position = new_position;
}

Direction Player::getDirection() const { return this->current_direction; }

void Player::setDirection(Direction new_direction) {
  if (up <= new_direction && new_direction <= right)
    current_direction = new_direction;
}

bool Player::isInScreen() const {
  if (current_position.x > 100 || current_position.x < -10)
    return false;
  return true;
}

void Player::move_up() {
  if (current_position.y < 12) {
    current_position.y = current_position.y + 1;
  }
  setDirection(up);
}

void Player::move_down() {
  if (current_position.y > 0) {
    current_position.y = current_position.y - 1;
  }
  setDirection(down);
}

void Player::move_right() {
  if (current_position.x < 93) {
    current_position.x = current_position.x + 0.5f;
  }
  setDirection(right);
}

void Player::move_left() {
  if (current_position.x > 0) {
    current_position.x = current_position.x - 0.5f;
  }
  setDirection(left);
}