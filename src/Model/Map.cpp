#include "Map.h"
#include "Game.h"
void Map::updateProps() {
    for (int i = 0; i < 13; i++) {
        environments.at(i)->updateProps();
    }
}

void Map::handleGame(Game *currentGame) {
    environments.at(currentGame->getPlayer()->getPosition().y)->handleGame(currentGame);
}