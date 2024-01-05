#ifndef GAME_H
#define GAME_H

#include "../Components/GameOverMenu.h"
#include "../Components/WinningMenu.h"
#include "../Driver.h"
#include "GameMenu.h"
#include "Map.h"
#include "Player.h"
#include "vector"
#include <memory>

class Water;
class Map;
class Driver;
class GameMenu;
class GameOverMenu;
class WinningMenu;

class Game {
public:
  Game(Driver *driver, std::shared_ptr<Map> map);
  Game(Driver *driver);
  ~Game();
  [[nodiscard]] virtual std::shared_ptr<Player> getPlayer() const;
  [[nodiscard]] virtual std::vector<std::shared_ptr<Player>> getWinnerPlayer() const;
  virtual void setPlayer(std::shared_ptr<Player> new_player);
  virtual void setMap(std::shared_ptr<Map> new_map);
  virtual void setGameMenu(std::shared_ptr<GameMenu> new_gameMenu);
  [[nodiscard]] virtual std::shared_ptr<GameMenu> getMenu() const;
  [[nodiscard]] virtual bool isOnPause() const;
  [[nodiscard]] virtual std::shared_ptr<Map> getMap() const;
  [[nodiscard]] virtual float getTime() const;
  [[nodiscard]] virtual std::shared_ptr<GameOverMenu> getGameOverMenu() const;
  [[nodiscard]] virtual std::shared_ptr<WinningMenu> getWinningMenu() const;
  [[nodiscard]] virtual float getFrameLeft() const;
  virtual void changeWinningState();
  virtual void changeLoosingState();
  [[nodiscard]] virtual bool isWinning() const;
  [[nodiscard]] virtual bool isLosing() const;
  [[nodiscard]] virtual bool isRunning() const;
  [[nodiscard]] virtual short getLives() const;
  virtual void addLife();
  virtual void restartGame();
  virtual void killPlayer();
  virtual void resetTime();
  virtual void decreaseTime();
  [[nodiscard]] virtual short getCombo() const;
  virtual void addCombo();
  virtual void resetCombo();
  [[nodiscard]] virtual int getScore() const;
  [[nodiscard]] virtual int getTimeOut() const;
  [[nodiscard]] virtual short getHighestPosition() const;
  virtual void handleScore();
  virtual void resetTimeOut();
  virtual void modifyHeight();
  virtual void resetHeight();
  virtual void decreaseTimeOut();
  virtual void win();
  virtual void triggerMenu();
  virtual void update();

private:
  std::shared_ptr<Player> _player;
  std::shared_ptr<Map> _map;
  std::shared_ptr<GameMenu> _gameMenu;
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
  bool _inMenu;
};

#endif
