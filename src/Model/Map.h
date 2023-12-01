#ifndef _MAP_H
#define _MAP_H

#include "Game.h"
#include "Environment.h"
#include "array"

class Environment;
class Game;

class Map {
private:
    std::array<Environment*, 13> environments;
public:
    Map() : environments{} {}
    ~Map() {
        for (int i = 0; i < environments.size(); i++) {
            delete environments.at(i);
        }
    }
    virtual Environment* getEnvironment(int index) {return environments.at(index);}
    virtual void setEnvironment(int index, Environment* new_environment) {environments[index] = new_environment;}

    virtual void updateProps();
    virtual void handleGame(Game* currentGame);
};

#endif