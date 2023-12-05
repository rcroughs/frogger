#include "GameController.h"

void GameController::keyPressed(int keycode) {
    switch (keycode) {
        case 'd':
            rightPressed = true;
            game->getPlayer()->move_right();
            game->getPlayer()->setDirection(right);
            break;
        case 'a':
        case 'q':
            leftPressed = true;
            game->getPlayer()->move_left();
            game->getPlayer()->setDirection(left);
            break;
        case 'w':
        case 'z':
            game->getPlayer()->move_up();
            game->getPlayer()->setDirection(up);
            break;
        case 's':
            game->getPlayer()->move_down();
            game->getPlayer()->setDirection(down);
    }
}

void GameController::keyReleased(int keycode) {
    switch (keycode) {
        case 'd':
            rightPressed = false;
            break;
        case 'a':
        case 'q':
            leftPressed = false;
            break;
    }
}

void GameController::updateMovement() {
    if (rightPressed) {
        game->getPlayer()->move_right();
    }
    if (leftPressed) {
        game->getPlayer()->move_left();
    }
}