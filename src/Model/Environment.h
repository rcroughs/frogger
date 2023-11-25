#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

class Game;

class Environment {
public:
    virtual void handleGame(Game* currentGame) =0;
    virtual void updateProps() =0;
};

#endif