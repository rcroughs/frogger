#ifndef SRC_GAMECONTROLLER_H
#define SRC_GAMECONTROLLER_H

#include "../Model/Game.h"
#include "array"
#include "vector"
#include "Controller.h"

class GameController : public Controller{
private:
    Game* game;
    bool leftPressed;
    bool rightPressed;
public:
    GameController(Game* game) : game{game}, leftPressed{false}, rightPressed{false} {}

    virtual void mouseMove(short loc_x, short loc_y) override {};
    virtual void mouseClick(short loc_x, short loc_y) override;
    virtual void keyPressed(int keycode) override;
    virtual void keyReleased(int keycode) override;
    virtual void updateMovement() override;
};




#endif //SRC_GAMECONTROLLER_H
