#ifndef SIDEWALK_H
#define SIDEWALK_H

#include "FL/Fl.H"
#include "../Environment.h"
#include "Props/Prop.h"

class Game;

class SideWalk : virtual public Environment {
private:
    Fl_Color color;

public:
    SideWalk() : color{FL_BLACK} {}

    virtual Fl_Color getColor() {return color;}
    virtual void setColor(Fl_Color new_color) {color = new_color;}

    virtual std::array<Prop*, 5> *getProps() override;
    virtual void handleGame(Game* currentGame) override;
    virtual void updateProps() override;
};

#endif