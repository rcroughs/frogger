#ifndef GAME_H
#define GAME_H

class Environment;

#include "Player.h"
#include "Map.h"

class Game {
private:
    Player player;
    Map map;
    bool isWinning;
    bool isLoosing;
public:
    Game(Player player, Map map) : player{player}, map{map}, isWinning{false}, isLoosing{false} {};

    virtual Player* getPlayer() {return &this->player;}
    virtual void setPlayer(Player new_player) {player = new_player;}
    virtual Map getMap() {return this->map;}
    virtual void setMap(Map new_map) {map = new_map;}
    virtual void changeWinningState() {isWinning = !isWinning;};
    virtual void changeLoosingState() {isLoosing = !isLoosing;};
};

#endif
