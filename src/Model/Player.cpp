#include "Player.h"

void Player::move_up() {
    if (current_position.y > 0) {
        current_position.y = current_position.y - 1;
    }
}

void Player::move_down() {
    if (current_position.y < 12) {
        current_position.y = current_position.y + 1;
    }
}

void Player::move_right() {
    // Au maximum 650 : 700 * 65 / 70 = 650 et le carré est de longueur 50
    if (current_position.x < 65) {
        current_position.x = current_position.x + 0.5f;
    }
}

void Player::move_left() {
    if (current_position.x > 0) {
        current_position.x = current_position.x - 0.5f;
    }
}