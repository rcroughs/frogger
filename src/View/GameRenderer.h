#include "../Model/Game.h"
#include "FL/Fl.H"
#include "FL/Fl_Box.H"
#include "FL/fl_draw.H"

class GameRenderer {
private:
    Game* game;
    const int WINDOW_HEIGHT;
    const int WINDOW_WIDTH;
public:
    GameRenderer(Game* game, int h, int w): game{game}, WINDOW_HEIGHT{h}, WINDOW_WIDTH{w} {}

    virtual Position getWindowPosition(Position gamePosition);
    virtual void draw();
};
