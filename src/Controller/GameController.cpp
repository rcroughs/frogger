#include "GameController.h"

void GameController::keyPressed(int keycode) {
    switch (keycode) {
        case 'd':
            game->getPlayer()->move_right();
            break;
        case 'a':
            game->getPlayer()->move_left();
            break;
        case 'w':
            game->getPlayer()->move_up();
            break;
        case 's':
            game->getPlayer()->move_down();
    }
}

