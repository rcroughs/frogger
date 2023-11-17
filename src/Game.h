#include "Model/Player.h"
#include "Model/Map.h"

class Game {
private:
    Player player;
    Map map;
public:
    Game(Player player, Map map) : player{player}, map{map} {}
    virtual ~Game();

    virtual Player getPlayer() {return this->player;}
    virtual void setPlayer(Player new_player) {player = new_player;}
    virtual Map getMap() {return this->map;}
    virtual void setMap(Map new_map) {map = new_map;}
};


