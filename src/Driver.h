#ifndef FROGGER_DRIVER_H
#define FROGGER_DRIVER_H

#include "Components/MenuComponents.h"
#include "Controller/Controller.h"
#include "Model/GameEditor.h"
#include "View/View.h"
#include <memory>

class MenuComponents;
class Game;
class GameEditor;

class Driver {
public:
  Driver();
  Driver(const Driver &driver) =default;
  virtual void launchGame(std::shared_ptr<Game> new_game);
  virtual void launchEditor();
  virtual void showMenu();
  virtual void showHomeScreen();
  virtual void refresh();

  // Levels
  virtual std::shared_ptr<Game> CreateLevel1();

  virtual void mouseMove(short loc_x, short loc_y) {
    if (_controller != nullptr)
      _controller->mouseMove(loc_x, loc_y);
  }
  virtual void mouseClick(short loc_x, short loc_y) {
    if (_controller != nullptr)
      _controller->mouseClick(loc_x, loc_y);
  }
  virtual void mouseReleased(short loc_x, short loc_y) {
    if (_controller != nullptr && _gameState == ON_EDIT)
      _controller->mouseRelease(loc_x, loc_y);
  }
  virtual void keyPressed(int keycode) {
    if (_controller != nullptr)
      _controller->keyPressed(keycode);
  }
  virtual void keyReleased(int keycode) {
    if (_controller != nullptr)
      _controller->keyReleased(keycode);
  }
  virtual void updateMovement() {
    if (_controller != nullptr)
      _controller->updateMovement();
  }

  virtual std::shared_ptr<GameEditor> getEditor() { return _editor; }

private:
  std::shared_ptr<View> _view;
  std::shared_ptr<Controller> _controller;
  std::shared_ptr<Game> _game;
  std::shared_ptr<GameEditor> _editor;
  std::shared_ptr<MenuComponents> _menu;
  enum GAME_STATE { MENU, ON_GAME, HOME_SCREEN, ON_EDIT };
  GAME_STATE _gameState = HOME_SCREEN;
  int _homescreen;
};

#endif // FROGGER_DRIVER_H
