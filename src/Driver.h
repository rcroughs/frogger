////////// Driver Header File - src/Driver.h //////////
// Description: This class handles the differents states of the game.
// Constructor takes: void
////////// FROGGER ///////////////////////////////////

#ifndef _FROGGER_DRIVER_H
#define _FROGGER_DRIVER_H

#include "Controller/Controller.h"
#include "View/View.h"
#include <memory>

// Forward declarations
class LevelSelector;
class MenuComponents;
class GameEditor;
class Game;

class Driver {
public:
  Driver();
  Driver(const Driver &driver) =default;

  // Launchers (used to change the game state)
  virtual void launchEditor();
  virtual void showMenu();
  virtual void showHomeScreen();
  virtual void launchLevelSelection();

  // Save a level as a file
  virtual void saveLevelAsFile(std::string fileName, std::string mapName,
                               std::string mapAuthor, std::string mapId);
  virtual void saveEditedLevelAsFile();

  // Refresh the game
  virtual void refresh();

  // Levels
  void LaunchGameFromFile(std::string filePath);
  virtual void launchLevelFromEditor();

  // Events handlers
  virtual void mouseMove(short loc_x, short loc_y);
  virtual void mouseClick(short loc_x, short loc_y);
  virtual void mouseReleased(short loc_x, short loc_y);
  virtual void keyPressed(int keycode);
  virtual void keyReleased(int keycode);
  virtual void updateMovement();

  // Getters
  virtual std::shared_ptr<GameEditor> getEditor();

  // Count the number of files in a directory
  virtual int countFiles(std::string directory);

private:
  std::shared_ptr<View> _view;
  std::shared_ptr<Controller> _controller;
  std::shared_ptr<GameEditor> _editor;
  std::shared_ptr<Game> _game;
  std::shared_ptr<MenuComponents> _menuComponents;
  std::shared_ptr<LevelSelector> _levelSelector;
  enum GAME_STATE { MENU, ON_GAME, HOME_SCREEN, ON_EDIT, LEVEL_SELECTION };
  GAME_STATE _gameState = HOME_SCREEN;
  int _homescreen;
};

#endif // _FROGGER_DRIVER_H
