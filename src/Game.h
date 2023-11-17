#include "Model/player.h"
#include "Model/Map.h"

class Game {
private:
    Player player;
    Map map;
public:
    Game(Player player, Map map) : player{player}, map{map} {}
    virtual ~Game();
    virtual Player getPlayer();
    virtual void setPlayer(Player new_player);
    virtual Map getMap();
    virtual void setMap();
};


