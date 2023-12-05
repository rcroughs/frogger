#ifndef SRC_GAMECONTROLLER_H
#define SRC_GAMECONTROLLER_H

#include "../Model/Game.h"
#include "array"
#include "vector"

class GameController {
private:
    Game* game;
    bool leftPressed;
    bool rightPressed;
public:
    GameController(Game* game) : game{game}, leftPressed{false}, rightPressed{false} {}

    virtual void mouseMove(short loc_x, short loc_y) {};
    virtual void mouseClick(short loc_x, short loc_y) {};
    virtual void keyPressed(int keycode);
    virtual void keyReleased(int keycode);
    virtual void updateMovement();
};




#endif //SRC_GAMECONTROLLER_H
