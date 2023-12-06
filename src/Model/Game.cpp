#include "Game.h"
#include <ctime>
#include "Environments/SideWalk.h"
#include "Environments/Water.h"
#include "Environments/Road.h"
#include "vector"

Game::Game() : player{new Player({45, 0}, up)}, map{new Map()}, winning{false}, loosing{false},
               lives{3}, time{30}, frameLeft{30*60}, score{0}, scoreFrameCounter{60} {

    map->setEnvironment(0, new SideWalk());
    for (int i = 1; i < 6; i++) {
        char circulation = '\0';
        float speedLimit = float(rand() % 3);
        if (speedLimit == 0) {speedLimit = 1;} else {speedLimit += 0.5;}
        if (i % 2 == 0) {circulation = 'r';} else {circulation = 'l';}
        map->setEnvironment(i, new Road(circulation, speedLimit));
        map->getEnvironment(i)->generateProps();
    }
    map->setEnvironment(6, new SideWalk());
    for (int i = 7; i < 9; i++) {
        srand(clock());
        float speed = float(rand() % 3);
        if (speed == 0) {speed = 1;} else {speed -= 0.5;}
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
    delete player;
}

void Game::restartGame() {
    if (lives > 0) {
        delete player;
        player = new Player({45, 0}, up);
        resetTime();
    } else {
        changeLoosingState();
    }
}

void Game::update() {
    map->updateProps();
    map->handleGame(this);
    if (!player->isInScreen()) {
        changeLoosingState();
    }
    if (getFrameLeft() <= 0) {
        killPlayer();
    }
    decreaseTime();
}

void Game::killPlayer() {
    lives--;
    restartGame();
}

void Game::win() {
    winnerPlayers.push_back(player);
    player = new Player({45, 0}, up);
    resetTime();
    if (winnerPlayers.size() == map->getEnvironment(12)->getProps().size()) {
        changeWinningState();
    }
}
