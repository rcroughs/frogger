#ifndef SIDEWALK_H
#define SIDEWALK_H

#include "FL/Fl.H"
#include "../Environment.h"
#include "Props/Prop.h"
#include "vector"

class Game;

class SideWalk : virtual public Environment {
private:
    Fl_Color color;
    std::vector<Prop*> props;
public:
    SideWalk() : color{FL_BLACK}, props{} {}

    virtual Fl_Color getColor() {return color;}
    virtual void setColor(Fl_Color new_color) {color = new_color;}

    virtual std::vector<Prop*> &getProps() override;
    virtual void handleGame(Game* currentGame) override;
    virtual void updateProps() override;
    virtual void generateProps(short id) override {}
};

#endif