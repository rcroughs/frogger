#include "Driver.h"

#include "Components/MenuComponents.h"
#include "Model/Environments/Road.h"
#include "Model/Environments/SideWalk.h"
#include "Model/Environments/Water.h"

#include "Controller/EditorController.h"
#include "Controller/GameController.h"
#include "Controller/MenuController.h"
#include "Model/GameEditor.h"
#include "Model/Map.h"
#include "View/EditorRenderer.h"
#include "View/GameRenderer.h"
#include "View/MenuDisplay.h"
#include "View/ViewHomeScreen.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <string>

void Driver::launchGame() {
  LaunchGameFromFile("maps/1.map");
  _controller = std::make_shared<GameController>(_game);
  _view = std::make_shared<GameRenderer>(_game, 700, 700, this);
  _menu = nullptr;
  _gameState = ON_GAME;
}

void Driver::launchEditor() {
  _game = nullptr;
  _editor = std::make_shared<GameEditor>(this, 700, 700);
  _controller = std::make_shared<EditorController>(_editor);
  _view = std::make_shared<EditorRenderer>(_editor, 700, 700);
  _menu = nullptr;
  _gameState = ON_EDIT;
  // A la fin : launchGame(game) dans GameEditor qui appelle via le driver
}

std::shared_ptr<Game> Driver::LaunchGameFromFile(std::string filePath) {
  std::ifstream inputFile(filePath);
  std::string mapName, mapId;

  std::getline(inputFile, mapName);
  std::getline(inputFile, mapId);

  std::shared_ptr<Map> map = _mapFactory->createMap(mapId);
  _game = std::make_shared<Game>(this, map);
  _game->setGameMenu(std::make_shared<GameMenu>(150, 100, this));
  Direction newDirection = up;
  _game->setPlayer(std::make_shared<Player>(Position{45, 0}, newDirection));
  inputFile.close();
  return _game;
}

void Driver::showMenu() {
  _menu = std::make_shared<MenuComponents>(this);
  _view = std::make_shared<MenuDisplay>(_menu);
  _controller = std::make_shared<MenuController>(_menu);
  _gameState = MENU;
}

void Driver::showHomeScreen() { _view = std::make_shared<ViewHomeScreen>(); }

void Driver::refresh() {
  if (_gameState == MENU) {
    _menu->update();
    _view->draw();
  } else if (_gameState == ON_GAME) {
    if (!_game->isOnPause()) {
      _game->update();
    }
    _view->draw();
    updateMovement();
  } else if (_gameState == HOME_SCREEN) {
    _view->draw();
    _homescreen++;
    if (_homescreen == 60) {
      showMenu();
    }
  } else if (_gameState == ON_EDIT) {
    // Pour le moment
    _view->draw();
    // updateMovement();
  }
}

Driver::Driver()
    : _editor{nullptr}, _view{nullptr}, _controller{nullptr}, _game{nullptr} {
  showHomeScreen();
}
