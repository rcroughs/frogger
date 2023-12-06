#include "GameController.h"

void GameController::keyPressed(int keycode) {
    if (!game->isOnPause()) {
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
                break;
        }
    }
    if (keycode == FL_Escape) {
        game->triggerMenu();
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

void GameController::mouseClick(short loc_x, short loc_y) {
    if (game->isOnPause()) {
        for (auto &button : game->getMenu()->getButtons()) {
            if (button->contains(loc_x, loc_y)) {
                button->onClick();
            }
        }
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