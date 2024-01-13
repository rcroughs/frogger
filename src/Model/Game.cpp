#include "Game.h"
#include "Environments/SideWalk.h"
#include "PauseMenu.h"
#include "Position.h"
#include "vector"
#include <fstream>
#include <memory>
#include <string>

Game::Game(Driver *driver, std::shared_ptr<Map> map, std::string filePath)
    : _filePath{filePath},
      _player{std::make_shared<Player>(Position{45, 0}, up)},
      _map{std::move(map)},
      _pauseMenu{std::make_shared<PauseMenu>(150, 100, driver)},
      _gameOverMenu(std::make_shared<GameOverMenu>(driver, filePath)),
      _winningMenu{std::make_shared<WinningMenu>(driver, filePath)}, _driver{driver},
      _winning{false}, _loosing{false}, _lives{3}, _time{30},
      _frameLeft{30 * 60}, _score{0}, _timeOut{0}, _combo{1},
      _highestPosition{0} {
  std::ifstream inputFile(filePath);
  for (int i = 0; i < 3; i++) {
    inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  std::string bf;
  std::getline(inputFile, bf);
  if (bf.empty()) {
    _highestScore = 0;
  } else {
    _highestScore = std::stoi(bf);
  }
  inputFile.close();
}

Game::Game(Driver *driver) : Game{driver, std::make_shared<Map>()} {}

Game::~Game() {}

std::shared_ptr<Player> Game::getPlayer() const { return this->_player; }

std::vector<std::shared_ptr<Player>> Game::getWinnerPlayer() const {
  return _winnerPlayers;
}

void Game::setPlayer(std::shared_ptr<Player> new_player) {
  _player = std::move(new_player);
}
void Game::setMap(std::shared_ptr<Map> new_map) { _map = std::move(new_map); }

void Game::setFilePath(std::string filePath) { _filePath = filePath; }

void Game::setPauseMenu(std::shared_ptr<PauseMenu> new_pauseMenu) {
  _pauseMenu = new_pauseMenu;
}

std::shared_ptr<PauseMenu> Game::getMenu() const { return _pauseMenu; }

bool Game::isOnPause() const { return _pauseMenu->isOpen(); }

std::shared_ptr<Map> Game::getMap() const { return this->_map; }

float Game::getTime() const { return _time; }

std::shared_ptr<GameOverMenu> Game::getGameOverMenu() const {
  return _gameOverMenu;
}

std::shared_ptr<WinningMenu> Game::getWinningMenu() const {
  return _winningMenu;
}

float Game::getFrameLeft() const { return _frameLeft; }

void Game::changeWinningState() { 
  _winning = true;
  if (_highestScore < _score) {
    std::string mapName, mapAuthor, mapId;
    std::ifstream inputFile(_filePath);
    std::getline(inputFile, mapName);
    std::getline(inputFile, mapAuthor);
    std::getline(inputFile, mapId);
    inputFile.close();
    std::ofstream outputFile(_filePath);
    outputFile << mapName << std::endl;
    outputFile << mapAuthor << std::endl;
    outputFile << mapId << std::endl;
    outputFile << _score << std::endl;
    outputFile.close();
  }
   
};

void Game::changeLoosingState() { _loosing = true; };

bool Game::isWinning() const { return _winning; };

bool Game::isLosing() const { return _loosing; };

bool Game::isRunning() const { return !_winning && !_loosing; };

short Game::getLives() const { return _lives; }

void Game::addLife() { ++_lives; }

void Game::restartGame() {
  if (_lives > 0) {
    _player = std::make_shared<Player>(Position{45, 0}, up);
    resetTime();
  } else {
    changeLoosingState();
  }
}

void Game::killPlayer() {
  _lives--;
  restartGame();
}

void Game::resetTime() { _frameLeft = _time * 60; }

void Game::decreaseTime() { _frameLeft--; }

short Game::getCombo() const { return _combo; }

void Game::addCombo() { _combo++; }

void Game::resetCombo() { _combo = 1; }

int Game::getScore() const { return _score; }

int Game::getTimeOut() const { return _timeOut; }

short Game::getHighestPosition() const { return _highestPosition; }

void Game::handleScore() {
  if (getPlayer()->getPosition().y < 12 &&
      getHighestPosition() < getPlayer()->getPosition().y) {
    if (getTimeOut() > 0) {
      addCombo();
    }
    modifyHeight();
    _score += getCombo() * 20;
  }
}

void Game::resetTimeOut() { _timeOut = 60; }

void Game::modifyHeight() {
  _highestPosition++;
  resetTimeOut();
}

void Game::resetHeight() { _highestPosition = 0; }

void Game::decreaseTimeOut() {
  if (_timeOut > 0) {
    _timeOut--;
  } else {
    resetCombo();
  }
}

void Game::win() {
  _winnerPlayers.push_back(_player);
  _player = std::make_shared<Player>(Position{45, 0}, up);
  resetTime();
  resetHeight();
  if (_winnerPlayers.size() == _map->getEnvironment(12)->getProps().size()) {
    changeWinningState();
  }
}

void Game::triggerMenu() { _pauseMenu->triggerMenu(); }

void Game::update() {
  decreaseTimeOut();
  if (_map != nullptr) {
    _map->updateProps();
    _map->handleGame(this);
  }
  if (!_player->isInScreen()) {
    changeLoosingState();
  }
  if (getFrameLeft() <= 0) {
    killPlayer();
  }
  decreaseTime();
}

void Game::movePlayerUp() {
    _player->moveUp();
}

void Game::movePlayerDown() {
    _player->moveDown();
}

void Game::movePlayerLeft() {
    _player->moveLeft();
}

void Game::movePlayerRight() {
    _player->moveRight();
}

std::string Game::getFilePath() const { return _filePath; }