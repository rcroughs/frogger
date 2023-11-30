#include "Player.h"

bool Player::isInScreen() {
    if (current_position.x > 100 || current_position.x < -10) return false;
    return true;
}

void Player::move_up() {
    if (current_position.y < 12) {
        current_position.y = current_position.y + 1;
    }
}

void Player::move_down() {
    if (current_position.y > 0) {
        current_position.y = current_position.y - 1;
    }
}

void Player::move_right() {
    if (current_position.x < 93) {
        current_position.x = current_position.x + 0.5f;
    }
}

void Player::move_left() {
    if (current_position.x > 0) {
        current_position.x = current_position.x - 0.5f;
    }
}