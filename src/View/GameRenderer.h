#ifndef _GAME_RENDERER_H
#define _GAME_RENDERER_H

#include "../Model/Game.h"
#include "FL/Fl.H"
#include "FL/Fl_Box.H"
#include "FL/fl_draw.H"
#include "View.h"

class GameRenderer : public View {
private:
    Game* game;
    const int WINDOW_HEIGHT;
    const int WINDOW_WIDTH;
public:
    GameRenderer(Game* game, int h, int w): game{game}, WINDOW_HEIGHT{h}, WINDOW_WIDTH{w} {}

    virtual Position getWindowPosition(Position gamePosition);
    virtual void drawVictory();
    virtual void drawGameOver();
    virtual void drawPlayer(Player* player);
    virtual void drawMap();
    virtual void drawHUD();
    virtual void drawMenu();
    void draw() override;
};

#endif