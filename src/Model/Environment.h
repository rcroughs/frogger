#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "FL/Fl.H"

class Game;

class Environment {
public:
    virtual Fl_Color getColor() =0;
    virtual void handleGame(Game* currentGame) =0;
    virtual void updateProps() =0;
};

#endif