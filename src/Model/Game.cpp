#include "Game.h"

void Game::modifyPlayer(char move) {
    switch (move) {
        case 'd':
            player.setPosition(Position{player.getPosition().x + 100, player.getPosition().y});
            break;
        case 'a':
            player.setPosition(Position{player.getPosition().x - 100, player.getPosition().y});
            break;
        case 'w':
            player.setPosition(Position{player.getPosition().x, player.getPosition().y + 100});
            break;
        case 's':
            player.setPosition(Position{player.getPosition().x, player.getPosition().y - 100});
    }
}
