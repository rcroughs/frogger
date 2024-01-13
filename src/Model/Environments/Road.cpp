#include "Road.h"
#include "Props/Car.h"
#include <ctime>
#include <memory>

Road::Road(char circulation, float speedLimit, short propsId)
    : Road{circulation, speedLimit} {
    generateProps(0);
}

Road::Road(char circulation, float speedLimit)
    : _color{FL_GRAY}, _props{}, _circulation{circulation},
      _speedLimit{speedLimit} {
  _id += "3";
  _id += _circulation == 'l' ? "0" : "1";
  std::string speedLimitId;
  if (_speedLimit == 1.0f) {
    speedLimitId = "1";
  } else if (_speedLimit == 1.5f) {
    speedLimitId = "2";
  } else if (_speedLimit == 2.5f) {
    speedLimitId = "3";
  }
  _id += speedLimitId;
}

Fl_Color Road::getColor() const { return _color; }

char Road::getCirculation() const { return _circulation; }

void Road::generateCars() {
  int usedSpace = 0;
  float position = 0.0;
  int carNumber = 0;
  short color;
  while (usedSpace + 30 < 100) {
    srand(clock());
    color = 0;
    if (carNumber != 0) {
      position += ((rand() % 3 + 2) * _props.at(carNumber - 1)->getSize());
    }
    color = rand() % 3;
    _props.push_back(
        std::make_shared<Car>(position, color, getCirculation(), _speedLimit));
    carNumber++;
    usedSpace = position + _props.at(carNumber - 1)->getSize();
    srand(clock());
  }
}

void Road::generateProps(short idc) { if (idc==0) generateCars(); }

std::vector<std::shared_ptr<Prop>> Road::getProps() const { return _props; }

void Road::handleGame(Game *currentGame) {
  for (auto &prop : _props) {
    if (prop->contains(currentGame->getPlayer()->getPosition().x)) {
      currentGame->killPlayer();
    }
  }
}

void Road::updateProps() {
  for (auto &prop : _props) {
    prop->move();
  }
}

std::string Road::getId() const { return _id; }
