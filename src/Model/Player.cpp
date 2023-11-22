#include "Player.h"

void Player::move_up() {
    current_position.y = current_position.y + 1;
}

void Player::move_down() {
    current_position.y = current_position.y - 1;
}

void Player::move_right() {
    current_position.x = current_position.x + 1;
}

void Player::move_left() {
    current_position.x = current_position.x - 1;
}