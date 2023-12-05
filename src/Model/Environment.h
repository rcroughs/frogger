#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "FL/Fl.H"
#include<vector>
#include "Environments/Props/Prop.h"

class Game;
class Prop;

class Environment {
public:
    virtual Fl_Color getColor() =0;
    virtual std::vector<Prop*> &getProps() =0;
    virtual void handleGame(Game* currentGame) =0;
    virtual void updateProps() =0;
    virtual void generateProps(short id = NULL) =0;
};

#endif