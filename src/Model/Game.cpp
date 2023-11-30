#include "Game.h"
#include "Environments/SideWalk.h"
#include "Environments/Water.h"

Game::Game() : player{{50, 0}, up}, map{}, winning{false}, loosing{false} {
    for (int i = 0; i < 7; i++) {
        map.setEnvironment(i, new SideWalk());
    }
    for (int i = 7; i < 12; i++) {
        srand(clock());
        int random = rand();
        float speed = float((i + random) % 3 + 0.5);
        if (speed == 0) {speed = 1;}
        map.setEnvironment(i, new Water(speed));
    }
    map.setEnvironment(12, new SideWalk());
}

void Game::update() {
    map.updateProps();
    map.handleGame(this);
}
