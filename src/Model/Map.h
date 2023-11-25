#ifndef _MAP_H
#define _MAP_H

#include "Environment.h"
#include "array"

class Environment;

class Map {
private:
    std::array<Environment*, 13> environments;
public:
    Map() : environments{} {}
    virtual Environment* getEnvironment(int index) {return environments.at(index);}
    virtual void setEnvironment(int index, Environment* new_environment) {environments[index] = new_environment;}

    virtual void updateProps();
    virtual void handleGame(Game* currentGame);
};

#endif