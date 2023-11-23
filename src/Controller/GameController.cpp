#include "GameController.h"

void GameController::keyPressed(int keycode) {
    switch (keycode) {
        case 'd':
            game->getPlayer()->move_right();
            game->getPlayer()->setDirection(right);
            break;
        case 'a':
            game->getPlayer()->move_left();
            game->getPlayer()->setDirection(left);
            break;
        case 'w':
            game->getPlayer()->move_up();
            game->getPlayer()->setDirection(up);
            break;
        case 's':
            game->getPlayer()->move_down();
            game->getPlayer()->setDirection(down);
    }
}

