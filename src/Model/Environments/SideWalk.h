#ifndef SIDEWALK_H
#define SIDEWALK_H

#include "FL/Fl.H"
#include "../Environment.h"
#include "../Game.h"

class SideWalk : public Environment {
private:
    Fl_Color color;

private:
    SideWalk() : color{FL_GRAY} {}

    Fl_Color getColor() {return color;}
    void setColor(Fl_Color new_color) {color = new_color;}

    virtual void handleGame(Game* currentGame);
};

#endif