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

void Driver::launchGame(std::shared_ptr<Game> new_game) {
  _controller = std::make_shared<GameController>(_game);
  _view = std::make_shared<GameRenderer>(new_game, 700, 700, this);
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

std::shared_ptr<Game> Driver::CreateLevel1() {
  _game = std::make_shared<Game>(this);
  _game->setGameMenu(std::make_shared<GameMenu>(150, 100, this));
  Direction newDirection = up;
  _game->setPlayer(std::make_shared<Player>(Position{45, 0}, newDirection));
  _game->getMap()->setEnvironment(0, new SideWalk());
  for (int i = 1; i < 6; i++) {
    char circulation = '\0';
    float speedLimit = float(rand() % 3);
    if (speedLimit == 0) {
      speedLimit = 1;
    } else {
      speedLimit += 0.5;
    }
    if (i % 2 == 0) {
      circulation = 'r';
    } else {
      circulation = 'l';
    }
    _game->getMap()->setEnvironment(i, new Road(circulation, speedLimit));
    _game->getMap()->getEnvironment(i)->generateProps();
  }
  _game->getMap()->setEnvironment(6, new SideWalk());
  for (int i = 7; i < 9; i++) {
    srand(clock());
    float speed = float(rand() % 3);
    if (speed == 0) {
      speed = 1;
    } else {
      speed -= 0.5;
    }
    _game->getMap()->setEnvironment(
        i, reinterpret_cast<Environment *>(new Water(speed)));
    _game->getMap()->getEnvironment(i)->generateProps(0);
  }
  _game->getMap()->setEnvironment(9, new Water());
  _game->getMap()->getEnvironment(9)->generateProps(2);
  for (int i = 10; i < 11; i++) {
    srand(clock());
    int random = rand();
    float speed = float((i + random) % 3 + 0.5);
    if (speed == 0) {
      speed = 1;
    }
    _game->getMap()->setEnvironment(
        i, reinterpret_cast<Environment *>(new Water(speed)));
    _game->getMap()->getEnvironment(i)->generateProps(0);
  }
  _game->getMap()->setEnvironment(11, new Water());
  _game->getMap()->getEnvironment(11)->generateProps(3);
  _game->getMap()->setEnvironment(12, new Water());
  _game->getMap()->getEnvironment(12)->generateProps(1);
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
