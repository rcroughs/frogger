#include "Game.h"
#include "Environments/SideWalk.h"
#include "Environments/Water.h"

Game::Game() : player{{50, 0}, up}, map{}, isWinning{false}, isLoosing{false} {
    for (int i = 0; i < 6; i++) {
        map.setEnvironment(i*2, new SideWalk());
        map.setEnvironment(i*2+1, new Water());
    }
    map.setEnvironment(12, new SideWalk());
};
