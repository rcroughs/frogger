#ifndef WATER_H
#define WATER_H

#include "../Environment.h"
#include "FL/Fl.H"
#include "Props/Prop.h"
#include "vector"


class Water : virtual public Environment {
private:
    Fl_Color color;
    std::vector<Prop*> props;
    bool isMoving;
    float flow;
public:
    Water() : isMoving{true}, color(FL_BLUE), flow(0) {}
    ~Water() {
        for (int i = 0; i < props.size(); i++) {
            delete props.at(i);
        }
    }
    Water(float speed) : isMoving{true}, color(FL_BLUE), flow(speed) {}
    virtual Fl_Color getColor() {return color;}
    void setColor(Fl_Color new_color) {color = new_color;}

    void generateProps(short id) override;

    virtual void generateLogs();
    virtual void generateLilyPads();

    virtual std::vector<Prop*>& getProps() override;
    virtual void handleGame(Game* currentGame) override;
    void updateProps() override;
};

#endif