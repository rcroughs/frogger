#ifndef FROGGER_PROP_H
#define FROGGER_PROP_H

#include "FL/Fl.H"
#include "../../Game.h"
#include <random>

class Game;

class Prop {
public:
    virtual float getPosition() =0;
    virtual float getRightCorner() =0;
    virtual Fl_Color getColor() =0;
    virtual float getSize() =0;
    virtual bool contains(float playerPosition) =0;
    virtual void moveRight() =0;
    virtual void moveLeft() =0;
    virtual void handleGame(Game* currentGame) =0;
};


#endif //FROGGER_PROP_H
