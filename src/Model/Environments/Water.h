#ifndef WATER_H
#define WATER_H

#include "../Environment.h"
#include "../Game.h"
#include "FL/Fl.H"
#include "Props/Log.h"
#include "array"


class Water : virtual public Environment {
private:
    Fl_Color color;
    std::array<Prop*, 5> logs;
    bool isMoving;
public:
    Water();
    virtual Fl_Color getColor() {return color;}
    void setColor(Fl_Color new_color) {color = new_color;}

    virtual std::array<Prop*, 5>* getProps() override;
    virtual void handleGame(Game* currentGame) override;
    void updateProps() override;
};

#endif