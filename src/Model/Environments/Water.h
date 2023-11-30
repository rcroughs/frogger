#ifndef WATER_H
#define WATER_H

#include "../Environment.h"
#include "../Game.h"
#include "FL/Fl.H"
#include "Props/Log.h"
#include "vector"


class Water : virtual public Environment {
private:
    Fl_Color color;
    std::vector<Prop*> logs;
    bool isMoving;
    float flow;
public:
    Water(float speed);
    virtual Fl_Color getColor() {return color;}
    void setColor(Fl_Color new_color) {color = new_color;}

    virtual std::vector<Prop*>& getProps() override;
    virtual void handleGame(Game* currentGame) override;
    void updateProps() override;
};

#endif