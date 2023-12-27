#ifndef FROGGER_DRIVER_H
#define FROGGER_DRIVER_H

#include "Components/LevelSelector.h"
#include "Components/MenuComponents.h"
#include "Model/GameEditor.h"
#include "Controller/Controller.h"
#include "Model/MapFactory.h"
#include "View/View.h"
#include <memory>

class MapFactory;
class LevelSelector;
class MenuComponents;
class GameEditor;

class Driver {
public:
  Driver();
  Driver(const Driver &driver) =default;
  virtual void launchEditor();
  virtual void showMenu();
  virtual void showHomeScreen();
  virtual void launchLevelSelection();
  virtual void refresh();

  // Levels
  void LaunchGameFromFile(std::string filePath);

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
  std::shared_ptr<GameEditor> _editor;
  std::shared_ptr<Game> _game;
  std::shared_ptr<MenuComponents> _menuComponents;
  std::shared_ptr<LevelSelector> _levelSelector;
  std::shared_ptr<MapFactory> _mapFactory;
  enum GAME_STATE { MENU, ON_GAME, HOME_SCREEN, ON_EDIT, LEVEL_SELECTION };
  GAME_STATE _gameState = HOME_SCREEN;
  int _homescreen;
};

#endif // FROGGER_DRIVER_H
