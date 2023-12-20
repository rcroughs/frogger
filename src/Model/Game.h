#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Map.h"
#include "vector"
#include "GameMenu.h"
#include "../Driver.h"
#include <memory>

class Water;
class Map;
class Driver;
class GameMenu;

class Game {
public:
    Game(Driver* driver);
    ~Game();
    virtual std::shared_ptr<Player> getPlayer() {return this->player;}
    virtual std::vector<std::shared_ptr<Player>> &getWinnerPlayer() {return winnerPlayers;}
    virtual void setPlayer(std::shared_ptr<Player> new_player) {player = std::move(new_player);}
    virtual void setMap(std::shared_ptr<Map> new_map) {map = new_map;}
    virtual void setGameMenu (std::shared_ptr<GameMenu> new_gameMenu) {gameMenu = new_gameMenu;}
    virtual std::shared_ptr<GameMenu> getMenu() {return gameMenu;}
    virtual bool isOnPause() {return inMenu;}
    virtual std::shared_ptr<Map> getMap() {return this->map;}
    virtual float getTime() {return time;}
    virtual float getFrameLeft() {return frameLeft;}
    virtual void changeWinningState() {winning = true;};
    virtual void changeLoosingState() {loosing  = true;};
    virtual bool isWinning() {return winning;};
    virtual bool isLosing() {return loosing;};
    virtual bool isRunning() {return !winning && !loosing;};
    virtual short getLives() {return lives;}
    virtual void addLife() {++lives;}
    virtual void restartGame();
    virtual void killPlayer();
    virtual void resetTime() {frameLeft = time*60;}
    virtual void decreaseTime() {frameLeft--;}
    virtual short getCombo() {return combo;}
    virtual short addCombo() {combo++;}
    virtual void resetCombo() {combo = 1;}
    virtual int getScore() {return score;}
    virtual int getTimeOut() {return timeOut;}
    virtual short getHighestPosition() {return highestPosition;}
    virtual void handleScore();
    virtual void resetTimeOut() {timeOut = 60;}
    virtual void modifyHeight() {highestPosition++; resetTimeOut(); }
    virtual void resetHeight() {highestPosition = 0;}
    virtual void decreaseTimeOut() {if (timeOut > 0) {timeOut--;} else {resetCombo();} }
    virtual void win();
    virtual void triggerMenu();
    virtual void update();
private:
    std::shared_ptr<Player> player;
    std::shared_ptr<Map> map;
    std::shared_ptr<GameMenu> gameMenu;
    Driver* driver;
    bool winning;
    bool loosing;
    short lives;
    std::vector<std::shared_ptr<Player>> winnerPlayers;
    float time;
    float frameLeft;
    int score;
    int timeOut;
    short combo;
    short highestPosition;
    bool inMenu;
};

#endif
