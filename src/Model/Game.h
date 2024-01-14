#ifndef _FROGGER_GAME_H
#define _FROGGER_GAME_H

#include "../Components/GameOverMenu.h"
#include "../Components/WinningMenu.h"
#include "../Driver.h"
#include "PauseMenu.h"
#include "Map.h"
#include "Player.h"
#include "vector"
#include <memory>

class Water;
class Map;
class Driver;
class PauseMenu;
class GameOverMenu;
class WinningMenu;

class Game {
public:
  Game(Driver *driver, std::shared_ptr<Map> map, std::string filePath = "");
  Game(Driver *driver);
  ~Game();

  /* Game handlers
   * Does not take any args and returns nothing
   */
  virtual void changeWinningState();
  virtual void changeLoosingState();
  virtual void addLife();
  virtual void restartGame();
  virtual void killPlayer();
  virtual void resetTime();
  virtual void decreaseTime();
  virtual void addCombo();
  virtual void resetCombo();
  virtual void handleScore();
  virtual void resetTimeOut();
  virtual void modifyHeight();
  virtual void resetHeight();
  virtual void decreaseTimeOut();
  virtual void win();
  virtual void triggerMenu();

  /* Getters
   * Does not take any args and returns the corresponding value
   */
  [[nodiscard]] virtual std::shared_ptr<Player> getPlayer() const;
  [[nodiscard]] virtual std::vector<std::shared_ptr<Player>> getWinnerPlayer() const;
  [[nodiscard]] virtual std::shared_ptr<PauseMenu> getMenu() const;
  [[nodiscard]] virtual std::shared_ptr<Map> getMap() const;
  [[nodiscard]] virtual std::shared_ptr<GameOverMenu> getGameOverMenu() const;
  [[nodiscard]] virtual std::shared_ptr<WinningMenu> getWinningMenu() const;
  [[nodiscard]] virtual float getTime() const;
  [[nodiscard]] virtual bool isOnPause() const;
  [[nodiscard]] virtual float getFrameLeft() const;
  [[nodiscard]] virtual bool isWinning() const;
  [[nodiscard]] virtual bool isLosing() const;
  [[nodiscard]] virtual bool isRunning() const;
  [[nodiscard]] virtual short getLives() const;
  [[nodiscard]] virtual short getCombo() const;
  [[nodiscard]] virtual int getScore() const;
  [[nodiscard]] virtual int getTimeOut() const;
  [[nodiscard]] virtual short getHighestPosition() const;
  [[nodiscard]] virtual std::string getFilePath() const;

  /* Setters
   * Does take the new value and returns nothing
   */
  virtual void setPlayer(std::shared_ptr<Player> new_player);
  virtual void setMap(std::shared_ptr<Map> new_map);
  virtual void setPauseMenu(std::shared_ptr<PauseMenu> new_pauseMenu);
  virtual void setFilePath(std::string filePath);
  virtual void generateMenu(std::string filePath);

  /* Update the game (move player, check collisions, etc)
   * Does not take any args and returns nothing
   */
  virtual void update();

  /* Move player in the map
   * Does not take any args and returns nothing
   * Buffer method for the player
   */
  virtual void movePlayerUp();
  virtual void movePlayerDown();
  virtual void movePlayerLeft();
  virtual void movePlayerRight();

private:
  std::string _filePath; // Path to the map file
  std::shared_ptr<Player> _player;
  std::shared_ptr<Map> _map;
  std::shared_ptr<PauseMenu> _pauseMenu;
  std::shared_ptr<GameOverMenu> _gameOverMenu;
  std::shared_ptr<WinningMenu> _winningMenu;
  Driver *_driver;
  bool _winning;
  bool _loosing;
  short _lives;
  std::vector<std::shared_ptr<Player>> _winnerPlayers;
  float _time;
  float _frameLeft;
  int _score;
  int _timeOut;
  short _combo;
  short _highestPosition;
  int _highestScore;
  
};

#endif
