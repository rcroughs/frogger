#include "Road.h"
#include "Props/Car.h"
#include <ctime>

void Road::generateCars() {
  int usedSpace = 0;
  float position = 0.0;
  int carNumber = 0;
  short color;
  while (usedSpace + 30 < 100) {
    srand(clock());
    color = 0;
    if (carNumber != 0) {
      position += ((rand() % 3 + 2) * props.at(carNumber - 1)->getSize());
    }
    color = rand() % 3;
    props.push_back(new Car{position, color, getCirculation(), speedLimit});
    carNumber++;
    usedSpace = position + props.at(carNumber - 1)->getSize();
    srand(clock());
  }
}

void Road::handleGame(Game *currentGame) {
  for (auto &prop : props) {
    if (prop->contains(currentGame->getPlayer()->getPosition().x)) {
      currentGame->killPlayer();
    }
  }
}

void Road::updateProps() {
  for (auto &prop : props) {
    prop->move();
  }
}

void Road::generateProps(short idc) { generateCars(); }

std::vector<Prop *> &Road::getProps() { return props; }