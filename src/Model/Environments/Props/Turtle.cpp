#include "Turtle.h"
#include <ctime>
#include <memory>

Turtle::Turtle(float position, short turtleNumber, float speed)
    : _position{position}, _turtleNumber{turtleNumber}, _visible{true},
      _invisibleTimer{0}, _speed{speed} {
  if (turtleNumber == 2) {
    _img = new Fl_PNG_Image("res/two_turtles.png");
    if (_img->fail() == Fl_Image::ERR_NO_IMAGE) {
      std::cout << "Image couln't load";
    }
    _size = 15.0f;
  } else if (turtleNumber == 3) {
    _img = new Fl_PNG_Image("res/three_turtles.png");
    if (_img->fail() == Fl_Image::ERR_FILE_ACCESS) {
      std::cout << "Image couln't load";
    }
    _size = 22.0f;
  }
}

Turtle::~Turtle() { delete _img; }

float Turtle::getPosition() const { return _position; }

float Turtle::getRightCorner() const { return _position + _size; }

Fl_Color Turtle::getColor() const { return FL_GREEN; }

float Turtle::getSize() const { return _size; }

bool Turtle::contains(float playerPosition) const {
  if (_position < playerPosition && playerPosition < getRightCorner() && _visible)
    return true;
  return false;
}

void Turtle::move() {
  if (getRightCorner() < 0) {
    _position = 100;
  } else {
    _position -= _speed * 0.13f;
  }
}

void Turtle::handleGame(Game *currentGame) {
  std::shared_ptr<Player> player = currentGame->getPlayer();
  player->setPosition(
      Position{player->getPosition().x - (_speed * 0.13f), player->getPosition().y});
}

bool Turtle::hasImage() const { return true; }

Fl_PNG_Image *Turtle::getImage() const { return _img; }

bool Turtle::isVisible() const { return _visible; }

void Turtle::update() {
  if (_visible) {
    srand(clock());
    if (rand() % 600 == 0) {
      _visible = false;
      _invisibleTimer = 180 + (rand() % 120);
    }
  } else {
    _invisibleTimer--;
    if (_invisibleTimer == 0) {
      _visible = true;
    }
  }
}