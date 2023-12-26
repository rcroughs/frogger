#include "MapFactory.h"
#include "Environments/SideWalk.h"
#include "Environments/Water.h"
#include "Environments/Road.h"
#include "Game.h"
#include <memory>
#include <string>

bool MapFactory::createLogEnvironment(std::string mapId, int& stringCount, std::shared_ptr<Map> map, int environmentCount) {
    int speed = std::stoi(std::string(&mapId.at(stringCount), 1));
    float flow;
    switch (speed) {
        case 1:
            flow = 1.0f;
            break;
        case 2:
            flow = 1.5f;
            break;
        case 3:
            flow = 2.0f;
            break;
        default:
            return false;
    }
    map->setEnvironment(environmentCount, new Water(flow));
    map->getEnvironment(environmentCount)->generateProps(0);
    stringCount += 1;
    return true;
}

bool MapFactory::createTurtleEnvironment(std::string mapId, int& stringCount, std::shared_ptr<Map> map, int environmentCount) {
    map->setEnvironment(environmentCount, new Water(std::stoi(std::string(&mapId.at(stringCount), 1))));
    stringCount += 1;
    map->getEnvironment(environmentCount)->generateProps(std::stoi(std::string(&mapId.at(stringCount), 1)));
    stringCount += 1;
    return true;
}

bool MapFactory::createRoadEnvironment(std::string mapId, int& stringCount, std::shared_ptr<Map> map, int environmentCount) {
    char direction = mapId.at(stringCount) == '0' ? 'l' : 'r';
    stringCount += 1;
    int speed = std::stoi(std::string(&mapId.at(stringCount), 1));
    float flow;
    switch (speed) {
        case 1:
            flow = 1.0f;
            break;
        case 2:
            flow = 1.5f;
            break;
        case 3:
            flow = 2.0f;
            break;
        default:
            return false;
    }
    map->setEnvironment(environmentCount, new Road(direction, flow));
    map->getEnvironment(environmentCount)->generateProps(0);
    stringCount += 1;
    return true;
}

std::shared_ptr<Map> MapFactory::createMap(std::string mapId) {
    std::shared_ptr<Map> map = std::make_shared<Map>();
    map->setEnvironment(0, new SideWalk());
    int stringCount = 0;
    int environmentCount = 1;
    while (stringCount < mapId.length()) {
        if (environmentCount == 13) {
            return nullptr;
        }
        if (mapId.at(stringCount) == '1') {
            stringCount++;
            createLogEnvironment(mapId, stringCount, map, environmentCount);
            environmentCount++;
        } else if (mapId.at(stringCount) == '2') {
            stringCount++;
            createTurtleEnvironment(mapId, stringCount, map, environmentCount);
            environmentCount++;
        } else if (mapId.at(stringCount) == '3') {
            stringCount++;
            createRoadEnvironment(mapId, stringCount, map, environmentCount);
            environmentCount++;
        } else if (mapId.at(stringCount) == '4') {
            stringCount++;
            map->setEnvironment(environmentCount, new SideWalk());
            environmentCount++;
        } else {
            return nullptr;
        }
    }
    map->setEnvironment(12, new Water());
    map->getEnvironment(12)->generateProps(1);
    return map;
}