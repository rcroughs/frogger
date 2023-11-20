#ifndef SRC_GAMECONTROLLER_H
#define SRC_GAMECONTROLLER_H

#include "../Model/Game.h"

class GameController {
private:
    Game game;
public:
    GameController(Game &game) : game{game} {}

    virtual void mouseMove(short loc_x, short loc_y) {};
    virtual void mouseClick(short loc_x, short loc_y) {};
    virtual void keyPressed(int keycode);
};




#endif //SRC_GAMECONTROLLER_H
