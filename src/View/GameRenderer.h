#include "../Model/Game.h"
#include "FL/Fl_Box.H"
#include "FL/fl_draw.H"

class GameRenderer {
private:
    Game game;
public:
    GameRenderer(Game &game): game{game} {}
    virtual void draw();
};
