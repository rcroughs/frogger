#include "Driver.h"

#include "Components/LevelSelector.h"
#include "Components/MenuComponents.h"
#include "Controller/LevelController.h"
#include "Model/Environments/SideWalk.h"

#include "Controller/EditorController.h"
#include "Controller/GameController.h"
#include "Controller/MenuController.h"
#include "Model/GameEditor.h"
#include "Model/Map.h"
#include "View/EditorRenderer.h"
#include "View/GameRenderer.h"
#include "View/LevelSelectorDisplay.h"
#include "View/MenuDisplay.h"
#include "View/ViewHomeScreen.h"
#include <memory>
#include <fstream>
#include <string>

void Driver::launchEditor() {
  _editor = std::make_shared<GameEditor>(this, 700, 700);
  _controller = std::make_shared<EditorController>(_editor);
  _view = std::make_shared<EditorRenderer>(_editor, 700, 700);
  _game = nullptr;
  _gameState = ON_EDIT;
  // A la fin : launchGame(game) dans GameEditor qui appelle via le driver
}

void Driver::launchLevelSelection() {
  _levelSelector = std::make_shared<LevelSelector>(this);
  _view = std::make_shared<LevelSelectorDisplay>(_levelSelector);
  _controller = std::make_shared<LevelController>(_levelSelector);
  _gameState = LEVEL_SELECTION;
}

void Driver::LaunchGameFromFile(std::string filePath) {
  std::ifstream inputFile(filePath);
  std::string mapName, mapAuthor, mapId;

  std::getline(inputFile, mapName);
  std::getline(inputFile, mapAuthor);
  std::getline(inputFile, mapId);

  std::shared_ptr<Map> map = _mapFactory->createMap(mapId);
  _editor = nullptr;
  _game = std::make_shared<Game>(this, map);
  _view = std::make_shared<GameRenderer>(_game, 700,750);
  _controller = std::make_shared<GameController>(_game);
  _gameState = ON_GAME;
  inputFile.close();
}

void Driver::showMenu() {
  _menuComponents = std::make_shared<MenuComponents>(this);
  _view = std::make_shared<MenuDisplay>(_menuComponents);
  _controller = std::make_shared<MenuController>(_menuComponents);
  _gameState = MENU;
}

void Driver::showHomeScreen() { _view = std::make_shared<ViewHomeScreen>(); }

void Driver::refresh() {
  if (_gameState == MENU) {
    _menuComponents->update();
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
  } else if (_gameState == LEVEL_SELECTION) {
    _view->draw();
  }
}

void Driver::mouseMove(short loc_x, short loc_y) {
  if (_controller != nullptr)
    _controller->mouseMove(loc_x, loc_y);
}

void Driver::mouseClick(short loc_x, short loc_y) {
  if (_controller != nullptr)
    _controller->mouseClick(loc_x, loc_y);
}

void Driver::mouseReleased(short loc_x, short loc_y) {
  if (_controller != nullptr && _gameState == ON_EDIT)
    _controller->mouseRelease(loc_x, loc_y);
}

void Driver::keyPressed(int keycode) {
  if (_controller != nullptr)
    _controller->keyPressed(keycode);
}

void Driver::keyReleased(int keycode) {
  if (_controller != nullptr)
    _controller->keyReleased(keycode);
}

void Driver::updateMovement() {
  if (_controller != nullptr)
    _controller->updateMovement();
}

std::shared_ptr<GameEditor> Driver::getEditor() { return _editor; }

Driver::Driver()
    : _view{nullptr}, _controller{nullptr}, _editor{nullptr}, _game{nullptr} {
  showHomeScreen();
}
