#include "GameController.h"

void GameController::keyPressed(int keycode) {
    switch (keycode) {
        case 'd':
            game->getPlayer()->setPosition(Position{game->getPlayer()->getPosition().x + 100, game->getPlayer()->getPosition().y});
            break;
        case 'a':
            game->getPlayer()->setPosition(Position{game->getPlayer()->getPosition().x - 100, game->getPlayer()->getPosition().y});
            break;
        case 'w':
            game->getPlayer()->move_up();
            break;
        case 's':
            game->getPlayer()->move_down();
    }
}

