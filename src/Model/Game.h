#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Map.h"

class Water;
class Map;

class Game {
private:
    Player* player {};
    Map* map;
    bool winning;
    bool loosing;
    short lives;
public:
    Game();
    ~Game();
    virtual Player* getPlayer() {return this->player;}
    virtual void setPlayer(Player* new_player) {player = new_player;}
    virtual Map* getMap() {return this->map;}
    virtual void setMap(Map* new_map) {map = new_map;}
    virtual void changeWinningState() {winning = !winning;};
    virtual void changeLoosingState() {loosing  = !loosing;};
    virtual bool isWinning() {return winning;};
    virtual bool isLosing() {return loosing;};
    virtual bool isRunning() {return !winning && !loosing;};
    virtual short getLives() {return lives;}
    virtual void addLife() {++lives;}
    virtual void restartGame();
    virtual void killPlayer();
    virtual void update();
};

#endif
