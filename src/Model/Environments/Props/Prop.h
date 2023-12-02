#ifndef FROGGER_PROP_H
#define FROGGER_PROP_H

#include "FL/Fl.H"
#include "../../Game.h"
#include "FL/Fl_PNG_Image.H"
#include <random>

class Game;

class Prop {
public:
    virtual float getPosition() =0;
    virtual float getRightCorner() =0;
    virtual Fl_Color getColor() =0;
    virtual float getSize() =0;
    virtual bool contains(float playerPosition) =0;
    virtual void move() =0;
    virtual void handleGame(Game* currentGame) =0;
    virtual bool hasImage() =0;
    virtual Fl_PNG_Image* getImage() =0;
};


#endif //FROGGER_PROP_H
