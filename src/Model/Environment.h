#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

class Game;

class Environment {
public:
    virtual ~Environment() =0;

    virtual void handleGame(Game* currentGame) =0;
    virtual void updateProps() =0;
};

#endif