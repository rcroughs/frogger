#include "Game.h"
#include <ctime>
#include "Environments/SideWalk.h"
#include "Environments/Water.h"

Game::Game() : player{new Player({50, 0}, up)}, map{new Map()}, winning{false}, loosing{false} {
    for (int i = 0; i < 7; i++) {
        map->setEnvironment(i, new SideWalk());
    }
    for (int i = 7; i < 9; i++) {
        srand(clock());
        int random = rand();
        float speed = float((i + random) % 3 + 0.5);
        if (speed == 0) {speed = 1;}
        map->setEnvironment(i, reinterpret_cast<Environment *>(new Water(speed)));
        map->getEnvironment(i)->generateProps(0);
    }
    map->setEnvironment(9, new Water());
    map->getEnvironment(9)->generateProps(2);
    for (int i = 10; i < 11; i++) {
        srand(clock());
        int random = rand();
        float speed = float((i + random) % 3 + 0.5);
        if (speed == 0) {speed = 1;}
        map->setEnvironment(i, reinterpret_cast<Environment *>(new Water(speed)));
        map->getEnvironment(i)->generateProps(0);
    }
    map->setEnvironment(11, new Water());
    map->getEnvironment(11)->generateProps(3);
    map->setEnvironment(12, new Water());
    map->getEnvironment(12)->generateProps(1);
}

Game::~Game() {
    for (int i = 0; i < 13; i++) {
        delete map->getEnvironment(i);
    }
}

void Game::update() {
    map->updateProps();
    map->handleGame(this);
    if (!player->isInScreen()) {
        changeLoosingState();
    }
}
