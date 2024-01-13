#include "Water.h"
#include "Props/LilyPad.h"
#include "Props/Log.h"
#include "Props/Turtle.h"
#include <ctime>
#include <memory>
#include <string>

Water::Water(float speed, short propsId): _color(FL_BLUE), _isMoving{true}, _flow(speed) {
  generateProps(propsId);
}

Water::Water(float speed) : _color(FL_BLUE), _isMoving{true}, _flow(speed) {}

Water::Water() : Water{0} {}

Fl_Color Water::getColor() const { return _color; }

void Water::setColor(Fl_Color new_color) { _color = new_color; }

void Water::setFlow(float new_flow) { _flow = new_flow; }

void Water::generateLogs() {
  int usedSpace = 0;
  int logCounter = 0;
  while (usedSpace + 20 < 100) {
    srand(clock());
    // Génération de la taille de la bûche
    int size = (rand() % 3 + 1) * 10;
    // Génération de la position
    float position = 0;
    if (logCounter - 1 >= 0) {
      position = _props.at(logCounter - 1)->getPosition() +
                 (_props.at(logCounter - 1)->getSize()) + 20;
    } else {
      position = (rand() % 3) * 10;
    }
    _props.push_back(
        std::make_shared<Log>(float(size), float(position), _flow));
    logCounter++;
    usedSpace = position + size;
    srand(clock());
  }
  _id += "1";
  std::string speedLimitId;
  if (_flow == 0.5f) {
    speedLimitId = "1";
  } else if (_flow == 1) {
    speedLimitId = "2";
  } else if (_flow == 1.5f) {
    speedLimitId = "3";
  }
  _id += speedLimitId;
}

void Water::generateLilyPads() {
  for (int i = 1; i < 5; i++) {
    _props.push_back(std::make_shared<LilyPad>(i * 20));
  }
}

void Water::generateTurtles(short turtleId) {
  for (int i = 0; i < 3; i++) {
    _props.push_back(std::make_shared<Turtle>(i * 30, turtleId));
  }
  _id += "2";
  std::string speedLimitId;
  if (_flow == 0.5f) {
    speedLimitId = "1";
  } else if (_flow == 1) {
    speedLimitId = "2";
  } else if (_flow == 1.5f) {
    speedLimitId = "3";
  }
  _id += speedLimitId;
  _id += std::to_string(turtleId);
}

void Water::generateProps(short id) {
  switch (id) {
  case 0:
    generateLogs();
    break;
  case 1:
    generateLilyPads();
    break;
  case 2:
    generateTurtles(id);
    break;
  case 3:
    generateTurtles(id);
  }
}

void Water::handleGame(Game *currentGame) {
  bool onProp = false;
  for (auto &prop : _props) {
    if (prop->contains(currentGame->getPlayer()->getPosition().x)) {
      onProp = true;
      prop->handleGame(currentGame);
    }
  }
  if (!onProp) {
    currentGame->killPlayer();
  }
}

std::vector<std::shared_ptr<Prop>> Water::getProps() const { return _props; }

void Water::updateProps() {
  if (_isMoving) {
    for (auto &prop : _props) {
      prop->update();
      prop->move();
    }
  }
}

std::string Water::getId() const { return _id; }