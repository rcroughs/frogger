#ifndef _MAP_H
#define _MAP_H

#include "Environment.h"
#include "array"

class Environment;

class Map {
private:
    std::array<Environment*, 13> environments;
};

#endif