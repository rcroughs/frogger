#include "Car.h"

Car::Car(float initPosition, short colorId, char direction, float speed)
    : _size{13.0f}, _leftCorner{initPosition}, _color{FL_RED},
      _direction{direction}, _speed{speed} {
  if (colorId == 0) {
    if (direction == 'l') {
      _img = new Fl_PNG_Image("res/red_car_left.png");
      if (_img->fail() == Fl_Image::ERR_NO_IMAGE) {
        std::cout << "Image couln't load";
      }
    } else {
      _img = new Fl_PNG_Image("res/red_car_right.png");
      if (_img->fail() == Fl_Image::ERR_NO_IMAGE) {
        std::cout << "Image couln't load";
      }
    }
  } else if (colorId == 1) {
    if (direction == 'l') {
      _img = new Fl_PNG_Image("res/blue_car_left.png");
      if (_img->fail() == Fl_Image::ERR_NO_IMAGE) {
        std::cout << "Image couln't load";
      }
    } else {
      _img = new Fl_PNG_Image("res/blue_car_right.png");
      if (_img->fail() == Fl_Image::ERR_NO_IMAGE) {
        std::cout << "Image couln't load";
      }
    }
  } else {
    if (direction == 'l') {
      _img = new Fl_PNG_Image("res/green_car_left.png");
      if (_img->fail() == Fl_Image::ERR_NO_IMAGE) {
        std::cout << "Image couln't load";
      }
    } else {
      _img = new Fl_PNG_Image("res/green_car_right.png");
      if (_img->fail() == Fl_Image::ERR_NO_IMAGE) {
        std::cout << "Image couln't load";
      }
    }
  }
};

Car::~Car() { delete _img; }

float Car::getPosition() const { return _leftCorner; }

float Car::getRightCorner() const { return _leftCorner + _size; }

float Car::getSize() const { return _size; }

Fl_Color Car::getColor() const { return _color; }

bool Car::contains(float playerPosition) const {
  if (playerPosition + 7 >= _leftCorner && playerPosition <= getRightCorner()) {
    return true;
  }
  return false;
}

void Car::move() {
  if (_direction == 'r') {
    if (getRightCorner() >= 130) {
      _leftCorner = 0 - _size;
    } else {
      _leftCorner = _leftCorner + _speed * 0.2f;
    }
  } else {
    if (getPosition() <= -30) {
      _leftCorner = 100 + _size;
    } else {
      _leftCorner = _leftCorner - _speed * 0.2f;
    }
  }
}

void Car::handleGame(Game *currentGame) {
  // pour l'instant ne sert à rien, les voitures ne font que tuer le joueur
  move();

  // unused parameter
  static_cast<void>(currentGame);
}

bool Car::hasImage() const { return true; }

Fl_PNG_Image *Car::getImage() const { return _img; };

bool Car::isVisible() const { return true; }

void Car::update() { return; }