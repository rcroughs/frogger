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

  virtual void mouseMove(short loc_x, short loc_y);
  virtual void mouseClick(short loc_x, short loc_y);
  virtual void mouseReleased(short loc_x, short loc_y);
  virtual void keyPressed(int keycode);
  virtual void keyReleased(int keycode);
  virtual void updateMovement();

  virtual std::shared_ptr<GameEditor> getEditor();

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
