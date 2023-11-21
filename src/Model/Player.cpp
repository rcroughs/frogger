#include "Player.h"

void Player::move_up() {
    current_position.y = current_position.y - (1.0/13.0) * 1000;
}

void Player::move_down() {
    current_position.y = current_position.y + (1.0/13.0) * 1000;
}
