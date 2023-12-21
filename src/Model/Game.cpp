#include "Game.h"
#include "Environments/SideWalk.h"
#include "Position.h"
#include "vector"
#include <memory>

Game::Game(Driver *driver)
    : driver{driver}, map{new Map()}, winning{false}, loosing{false}, lives{3},
      time{30}, frameLeft{30 * 60}, score{0}, timeOut{0}, combo{1},
      highestPosition{0}, inMenu{false} {}

Game::~Game() {
  for (int i = 0; i < 13; i++) {
    delete map->getEnvironment(i);
  }
}

void Game::restartGame() {
  if (lives > 0) {
    player = std::make_shared<Player>(Position{45, 0}, up);
    resetTime();
  } else {
    changeLoosingState();
  }
}

void Game::handleScore() {
  if (getPlayer()->getPosition().y < 12 &&
      getHighestPosition() < getPlayer()->getPosition().y) {
    if (getTimeOut() > 0) {
      addCombo();
    }
    modifyHeight();
    score += getCombo() * 20;
  }
}

void Game::update() {
  decreaseTimeOut();
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
  player = std::make_shared<Player>(Position{0, 45}, up);
  resetTime();
  resetHeight();
  if (winnerPlayers.size() == map->getEnvironment(12)->getProps().size()) {
    changeWinningState();
  }
}

void Game::triggerMenu() { inMenu = !inMenu; }
