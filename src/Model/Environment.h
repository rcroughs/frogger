#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "FL/Fl.H"
#include<array>
#include "Environments/Props/Prop.h"

class Game;

class Environment {
public:
    virtual Fl_Color getColor() =0;
    virtual std::array<Prop*, 5> *getProps() =0;
    virtual void handleGame(Game* currentGame) =0;
    virtual void updateProps() =0;
};

#endif